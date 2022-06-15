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
    bool do_leak_detection_between_handlers;
    bool do_leak_reporting;
    bool do_garbage_collection;
    bool traversal_in_progress;
    int mark_speculative;
    char *current_handler_name;
    void (*nodePrintFunc)(void *);
    int handler_nesting_level;
    int allocation_count;
    int allocation_size_count;
    int managed_allocation_count;
    int managed_allocation_size_count;
    int free_count;
    int managed_free_count;
    int managed_free_size_count;
    int leak_count;
    int leak_size_count;
};

/* Default function getCurrentActionName */
char *actionNameUnknown(void *node) {
    return "Unknown";
}

/* Default function nodePrintFunc */
void nodePrintNotSet() {
    fprintf(stderr, "No print function set");
}

static struct mem_manager mem_manager = {
    .getCurrentActionName = actionNameUnknown,
    .allocations_list = NULL,
    .do_leak_detection = true,
    .do_leak_detection_between_handlers = false,
    .do_leak_reporting = false,
    .do_garbage_collection = true,
    .traversal_in_progress = false,
    .mark_speculative = 0,
    .current_handler_name = NULL,
    .nodePrintFunc = nodePrintNotSet,
    .handler_nesting_level = 0,
    .allocation_count = 0,
    .allocation_size_count = 0,
    .managed_allocation_count = 0,
    .managed_allocation_size_count = 0,
    .free_count = 0,
    .managed_free_count = 0,
    .managed_free_size_count = 0,
    .leak_count = 0,
    .leak_size_count = 0,
};

struct mem_header {
    int size;
    int mark;
    bool speculative_leaked;
    enum mem_type type;
    char *allocate_action_name;
    char *allocate_handler_name;
    char *leak_handler_name;
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
 * Set the Current Action Name Function
 * @param f The function to be used for retrieving the current action name
 */
void MEMsetCurrentActionNameFunction(char *(*f)()) {
    mem_manager.getCurrentActionName = f;
}

/**
 * Set the Node Print Function
 * @param f The function to be used for printing node information
 */
void MEMsetNodePrintFunc(void (*f)(void *)) {
    mem_manager.nodePrintFunc = f;
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
 * Set the speculative mark mode flag.
 */
void MEMsetMarkSpeculative(int mark_speculative) {
    mem_manager.mark_speculative = mark_speculative;
}

/**
 * Get the current handler name
 */
char *MEMgetCurrentHandlerName() {
    return mem_manager.current_handler_name;
}

/**
 * Set the current handler name
 */
void MEMsetCurrentHandlerName(char *name) {
    mem_manager.current_handler_name = name;
}

/**
 * Get do_leak_detection flag
 */
bool MEMdoLeakDetection() {
    return mem_manager.do_leak_detection;
}

/**
 * Get do_leak_detection_between_handlers flag
 */
bool MEMdoLeakDetectionBetweenHandlers() {
    return mem_manager.do_leak_detection_between_handlers;
}

/**
 * Increment the handler nesting level
 */
void MEMincrementHandlerNestingLevel() {
    mem_manager.handler_nesting_level++;
}

/**
 * Decrement the handler nesting level
 */
void MEMdecrementHandlerNestingLevel() {
    mem_manager.handler_nesting_level--;
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
    /* Print statistics */
    if (mem_manager.do_leak_reporting) {
        printf("===================== Memory statistics =====================\n");
        printf("             managed/total\n");
        printf("Allocations: %d/%d (total size: %d/%d)\n", mem_manager.managed_allocation_count,
                                                           mem_manager.allocation_count,
                                                           mem_manager.managed_allocation_size_count,
                                                           mem_manager.allocation_size_count);
        printf("Frees:       %d/%d (total size: %d/Unknown)\n", mem_manager.managed_free_count,
                                                                mem_manager.free_count,
                                                                mem_manager.managed_free_size_count);
        printf("-------------------------------------------------------------\n");
        printf("             managed\n");
        printf("Leaked:      %d (total size: %d)\n", mem_manager.leak_count,
                                                     mem_manager.leak_size_count);
        printf("=============================================================\n");
    }

    /* Cleanup adminstrative data */
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

    /* Update statistics */
    mem_manager.allocation_count++;
    mem_manager.allocation_size_count += size;

    /* Set the mem_header values and update administrative structure
     * in case of managed allocation */
    if (mem_manager.traversal_in_progress && mem_manager.do_leak_detection) {
        struct mem_header *header = (struct mem_header *)ptr;

        /* Update statistics */
        mem_manager.managed_allocation_count++;
        mem_manager.managed_allocation_size_count += size;

        /* Set mem header values */
        header->size = size;
        header->mark = false;
        header->speculative_leaked = false;
        header->type = MEM_TYPE_UNKNOWN;
        header->allocate_action_name = mem_manager.getCurrentActionName();
        header->allocate_handler_name = mem_manager.current_handler_name;
        header->leak_handler_name = mem_manager.current_handler_name;

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

            /* Update statistics */
            mem_manager.managed_free_count++;
            mem_manager.managed_free_size_count += header->size;
        } else if (in_progress_temp && mem_manager.do_leak_reporting) {
            /* Memory is not managed, but traversal is in progress,
             * so this is either a double free or memory that wasn't
             * allocated with our functions when it should be. */
            fprintf(stderr, "Error: memory at address %p was not allocated by MEM or STR functions, or was already freed.\n", address);
        }
        mem_manager.traversal_in_progress = in_progress_temp;
    }

    /* Update statistics */
    mem_manager.free_count++;

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
        /* Memory is not managed, so this is memory that wasn't
         * allocated with our functions when it should be. */
        if (mem_manager.do_leak_reporting) {
            fprintf(stderr, "Error: memory at address %p was not allocated by MEM or STR functions.\n", address);
        }
        return;
    }

    /* Mark the address as being in use */
    if (mem_manager.mark_speculative == 1) {
        header->mark = mem_manager.handler_nesting_level;
    } else if (mem_manager.mark_speculative == 2) {
        if (header->mark == mem_manager.handler_nesting_level) {
            header->mark--;
        }
    } else {
        header->mark = true;
    }
}

/**
 * Check whether an address is still in use, if not, report on the leak.
 * @param address The address to check.
 */
void MEMcheckSingleEntry(void *address) {
    struct mem_header *header = (struct mem_header *)address;
    if (mem_manager.mark_speculative) {
        /* Speculative run, just set the probable source,
         * don't consider the leak final yet */
        if (header->mark == mem_manager.handler_nesting_level) {
            if (!header->speculative_leaked) {
                /* Set the current handler name as the probable leak source */
                header->leak_handler_name = mem_manager.current_handler_name;
                header->speculative_leaked = true;
                header->mark = 0;
            } else {
                /* Set the mark int back down to the previous nesting level */
                header->mark--;
            }
        } else if (header->mark == (mem_manager.handler_nesting_level - 1) && header->speculative_leaked) {
            header->speculative_leaked = false;
        }
        return;
    }

    if (!header->mark) {
        /* Update statistics */
        mem_manager.leak_count++;
        mem_manager.leak_size_count += header->size;

        /* Report on leak */
        if (mem_manager.do_leak_reporting) {
            fprintf(stderr, "Error: memory leak detected.\n");
            fprintf(stderr, "    Allocated in \x1b[32m%s\x1b[0m, handler: \x1b[92m%s\x1b[0m\n", header->allocate_action_name, header->allocate_handler_name);
            if (mem_manager.do_leak_detection_between_handlers) {
                fprintf(stderr, "    Leaked in \x1b[32m%s\x1b[0m, handler: \x1b[92m%s\x1b[0m\n", mem_manager.getCurrentActionName(), header->leak_handler_name);
            } else {
                fprintf(stderr, "    Leaked in \x1b[32m%s\x1b[0m\n", mem_manager.getCurrentActionName());
            }
            fprintf(stderr, "    Type: \x1b[34m%s\x1b[0m\n", MEMtypeToName(header->type));
            switch (header->type) {
                case MEM_TYPE_NODE:
                    fprintf(stderr, "        Node info: \x1b[35m");
                    mem_manager.nodePrintFunc(MEM_DATA(header));
                    fprintf(stderr, "\x1b[0m\n");
                    break;
                case MEM_TYPE_STR:
                    fprintf(stderr, "        String value: `\x1b[33m%s\x1b[0m`\n", (char *)MEM_DATA(address));
                    break;
                default:
                    break;
            }
            fprintf(stderr, "\n");
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