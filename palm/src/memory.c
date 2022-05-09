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
    return STRcpy("Unknown");
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
 * this function calls the CTIabortOufOfMemory function and exists.
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
 * this function calls the CTIabortOufOfMemory function and exists.
 * @param size Amount to allocate.
 * @return A pointer to an allocated structure.
 */
void *MEMmalloc(size_t size) {
    return MEMmallocCallocGeneric(size, 1, false);
}

/**
 * Allocate memory using calloc. If memory can not be allocated
 * this function calls the CTIabortOufOfMemory function and exists.
 * @param size Size of individual item.
 * @param nitems Number of items to allocate.
 * @return A pointer to an allocated structure.
 */
void *MEMcalloc(size_t nitems, size_t size) {
    return MEMmallocCallocGeneric(size, nitems, true);
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

    /* If this free was called during a traversal and leak detection is
     * enabled, set the address to the header address */
    if (mem_manager.do_leak_detection && mem_manager.traversal_in_progress) {
        struct mem_header *header = MEM_HEADER(address);

        /* Remove address from list of managed addresses
         * and check for double free */
        mem_manager.traversal_in_progress = false;
        if (!LLremove(mem_manager.allocations_list, header)) {
            printf("Double free of address %p in %s (allocated in %s with type %d)\n", header, mem_manager.getCurrentActionName(), header->allocate_action_name, header->type);
        }
        mem_manager.traversal_in_progress = true;

        address = (void *)header;
    }

    /* Free the memory */
    free(address);
    address = NULL;
    return address;
}

void *MEMcopy(size_t size, void *mem)
{
    printf("MEMcopy is used: it doesn't yet work fully with managed memory!\n");
    // TODO: Handle copying of managed memory
    void *result;

    result = MEMmalloc(size);
    result = memcpy(result, mem, size);

    return result;
}