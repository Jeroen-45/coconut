#include "palm/memory.h"

#include <stdlib.h>
#include <string.h>

#include "palm/dbug.h"
#include "palm/ctinfo.h"
#include "palm/str.h"
#include "palm/linked_list.h"

// Memory header access macros
#define MEM_HEADER(data_ptr) (((struct mem_header *)(data_ptr) - 1))
#define MEM_DATA(header_ptr) (((void *)header_ptr + sizeof(struct mem_header)))


struct mem_manager {
    char *(*getCurrentActionName)();
    linked_list_st *allocations_list;
    bool do_leak_detection;
    bool do_garbage_collection;
    bool traversal_in_progress;
    char *current_handler_name;
};

/* Default function getCurrentActionName */
char *actionNameUnknown() {
    return "Unknown";
}

static struct mem_manager mem_manager = {
    .getCurrentActionName = actionNameUnknown,
    .allocations_list = NULL,
    .do_leak_detection = true,
    .do_garbage_collection = true,
    .traversal_in_progress = false,
    .current_handler_name = NULL,
};

struct mem_header {
    bool mark;
    enum mem_type type;
    char *allocate_action_name;
    char *allocate_handler_name;
};

/**
 * Get name for memory type.
 * @return A string representation of the given memory type
 */
char *MEMtypeToName(enum mem_type type) {
    switch (type) {
        case MEM_TYPE_NODE:
            return "Node";
        case MEM_TYPE_NODE_DATA:
            return "Node Data";
        case MEM_TYPE_STR:
            return "String";
        case MEM_TYPE_UNKNOWN:
        default:
            return "Unknown";
    }
}

/**
 * Set the Current Action Name Function object
 * @param f The function to be used for retrieving the current action name
 */
void MEMsetCurrentActionNameFunction(char *(*f)()) {
    mem_manager.getCurrentActionName = f;
}

/**
 * Get the traversal in progress flag
 */
bool MEMgetTraversalInProgress() {
    return mem_manager.traversal_in_progress;
}

/**
 * Set the traversal in progress flag
 */
void MEMsetTraversalInProgress(bool in_progress) {
    mem_manager.traversal_in_progress = in_progress;
}

/**
 * Set the current handler name
 */
void MEMsetCurrentHandlerName(char *name) {
    mem_manager.current_handler_name = name;
}

/* Get do_leak_detection flag */
bool MEMdoLeakDetection() {
    return mem_manager.do_leak_detection;
}

/**
 * Initialise the memory manager
 */
void MEMmanagerInit() {
    mem_manager.allocations_list = LLnew();
}

/**
 * Cleanup memory manager data
 */
void MEMmanagerCleanup() {
    LLdelete(mem_manager.allocations_list);
}

/**
 * Allocate memory using malloc or calloc. If memory can not be allocated
 * this function calls the CTIabortOufOfMemory function and exits.
 * @param size Amount to allocate.
 * @param nitems Number of items to allocate in case of calloc.
 * @param use_calloc When true, use calloc instead of malloc.
 * @return A pointer to an allocated structure.
 */
void *MEMmallocCallocGeneric(size_t size, size_t nitems, bool use_calloc)
{
    void *ptr;

    DBUG_ASSERT((size >= 0), "called with negative size!");

    if (size == 0) {
        return NULL;
    }

    /* Add header for leak detection if it is enabled
     * and the allocation was made during a traversal */
    if (mem_manager.traversal_in_progress && mem_manager.do_leak_detection) {
        size += sizeof(struct mem_header);
    }

    /* Allocate memory */
    if (use_calloc) {
        ptr = calloc(nitems, size);
    } else {
        ptr = malloc(size);
    }

    /*
    * Since some UNIX system (e.g. ALPHA) do return NULL for size 0 as well
    * we do complain for ((NULL == tmp) && (size > 0)) only!!
    */
    if (ptr == NULL) {
        CTIabortOutOfMemory(size);
    }

    /* Set the mem_header values and update administrative structure
     * in case of managed allocation */
    if (mem_manager.traversal_in_progress && mem_manager.do_leak_detection) {
        struct mem_header *header = (struct mem_header *)ptr;

        /* Set mem header values */
        header->mark = false;
        header->type = MEM_TYPE_UNKNOWN;
        header->allocate_action_name = mem_manager.getCurrentActionName();
        header->allocate_handler_name = mem_manager.current_handler_name;

        /* Add address to list of managed addresses */
        mem_manager.traversal_in_progress = false;
        LLadd(mem_manager.allocations_list, ptr);
        mem_manager.traversal_in_progress = true;

        /* Return pointer to data */
        ptr = MEM_DATA(header);
    }

    return ptr;
}

/**
 * Allocate memory using malloc. If memory can not be allocated
 * this function calls the CTIabortOufOfMemory function and exits.
 * @param size Amount to allocate.
 * @return A pointer to an allocated structure.
 */
void *MEMmalloc(size_t size) {
    return MEMmallocCallocGeneric(size, 1, false);
}

/**
 * Allocate unmanaged memory using malloc. If memory can not be allocated
 * this function calls the CTIabortOufOfMemory function and exits.
 * @param size Amount to allocate.
 * @return A pointer to an allocated structure.
 */
void *MEMmallocUnmanaged(size_t size) {
    void *ptr;
    bool temp = mem_manager.traversal_in_progress;

    mem_manager.traversal_in_progress = false;
    ptr = MEMmalloc(size);
    mem_manager.traversal_in_progress = temp;
    return ptr;
}

/**
 * Allocate memory using calloc. If memory can not be allocated
 * this function calls the CTIabortOufOfMemory function and exits.
 * @param nitems Number of items to allocate.
 * @param size Size of individual item.
 * @return A pointer to an allocated structure.
 */
void *MEMcalloc(size_t nitems, size_t size) {
    return MEMmallocCallocGeneric(size, nitems, true);
}

/**
 * Allocate unmanaged memory using calloc. If memory can not be allocated
 * this function calls the CTIabortOufOfMemory function and exits.
 * @param nitems Number of items to allocate.
 * @param size Amount to allocate.
 * @return A pointer to an allocated structure.
 */
void *MEMcallocUnmanaged(size_t nitems, size_t size) {
    void *ptr;
    bool temp = mem_manager.traversal_in_progress;

    mem_manager.traversal_in_progress = false;
    ptr = MEMcalloc(nitems, size);
    mem_manager.traversal_in_progress = temp;
    return ptr;
}

/**
 * Allocate managed memory with a header containing extra details added in
 * @param size Amount to allocate.
 * @param type The memory type being allocated.
 * @return A pointer to an allocated structure.
 */
void *MEMmallocWithType(size_t size, enum mem_type type)
{
    /* Allocate memory */
    void *data = MEMmalloc(size);

    /* Set the type in the header in case of managed allocation */
    if (mem_manager.traversal_in_progress && mem_manager.do_leak_detection) {
        struct mem_header *header = MEM_HEADER(data);
        header->type = type;
    }

    /* Return the pointer to the memory after the header */
    return data;
}

/**
 * Free memory. Returns NULL, but allows to do assignment to freed structure.
 * @param address address to free.
 */
void *MEMfree(void *address)
{
    if (address == NULL) {
        return NULL;
    }

    /* Attempt to remove address from list of managed addresses
     * if leak detection is enabled */
    if (mem_manager.do_leak_detection) {
        struct mem_header *header = MEM_HEADER(address);
        bool in_progress_temp = mem_manager.traversal_in_progress;
        mem_manager.traversal_in_progress = false;
        if (LLremove(mem_manager.allocations_list, header)) {
            /* Memory is managed, free from start of header */
            address = (void *)header;
        } else if (in_progress_temp) {
            /* Memory is not managed, but traversal is in progress,
             * so this is either a double free or memory that wasn't
             * allocated with our functions when it should be. */
            fprintf(stderr, "Error: memory at address %p was not allocated by MEM or STR functions, or was already freed.\n", address);
        }
        mem_manager.traversal_in_progress = in_progress_temp;
    }

    /* Free the memory */
    free(address);
    address = NULL;
    return address;
}

void *MEMcopy(size_t size, void *mem)
{
    void *result;

    result = MEMmalloc(size);
    result = memcpy(result, mem, size);

    /* Copy type if mem and result are managed */
    if (mem_manager.do_leak_detection && mem_manager.traversal_in_progress
        && LLin(mem_manager.allocations_list, MEM_HEADER(mem))) {
        struct mem_header *header = MEM_HEADER(mem);
        struct mem_header *header_result = MEM_HEADER(result);
        header_result->type = header->type;
    }

    return result;
}

/**
 * Mark an address as still being in use.
 */
void MEMmark(void *address) {
    if (address == NULL) {
        return;
    }

    /* Check whether the address is actually managed */
    struct mem_header *header = MEM_HEADER(address);
    if (!LLin(mem_manager.allocations_list, header)) {
        fprintf(stderr, "Error: memory found in the AST that was not allocated by MEM or STR functions.\n");
        return;
    }

    /* Mark the address as being in use */
    header->mark = true;
}

/**
 * Check whether an address is still in use, if not, report on the leak.
 * @param address The address to check.
 */
void MEMcheckSingleEntry(void *address) {
    struct mem_header *header = (struct mem_header *)address;
    if (!header->mark) {
        /* Report on leak */
        // TODO: expand reporting
        // fprintf(stderr, "Error: memory leak detected.\n");
        // fprintf(stderr, "    Allocated in %s\n", header->allocate_action_name);
        // fprintf(stderr, "    Leaked in %s\n", mem_manager.getCurrentActionName());
        // fprintf(stderr, "    Type: %s\n", MEMtypeToName(header->type));
        switch (header->type) {
            case MEM_TYPE_STR:
                // fprintf(stderr, "        String value: `%s`\n", (char *)MEM_DATA(address));
                break;
            default:
                break;
        }

        /* Free leaked memory if garbage collection is enabled */
        if (mem_manager.do_garbage_collection) {
            MEMfree(MEM_DATA(header));
        }

        /* Remove memory from list of managed addresses */
        bool in_progress_temp = mem_manager.traversal_in_progress;
        mem_manager.traversal_in_progress = false;
        LLremove(mem_manager.allocations_list, address);
        mem_manager.traversal_in_progress = in_progress_temp;
    } else {
        header->mark = false;
    }
}

/**
 * Check if any addresses were leaked and report on them if they are.
 */
void MEMcheck() {
    /* Traverse the list of managed addresses and check for any unmarked ones */
    LLiterate(mem_manager.allocations_list, MEMcheckSingleEntry);
}