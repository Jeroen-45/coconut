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
};

/* Default function getCurrentActionName */
char *actionNameUnknown() {
    return STRcpy("Unknown");
}

static struct mem_manager mem_manager = {
    .getCurrentActionName = actionNameUnknown,
    .allocations_list = NULL,
};

struct mem_header {
    bool mark;
    enum mem_type type;
    char *allocate_action_name;
};

/**
 * Set the Current Action Name Function object
 * @param f The function to be used for retrieving the current action name
 */
void MEMsetCurrentActionNameFunction(char *(*f)()) {
    mem_manager.getCurrentActionName = f;
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
 * Allocate memory. If memory can not be allocated this function
 * calls the CTIabortOufOfMemory function and exists.
 * @param size Amount to allocate.
 * @return A pointer to an allocated structure.
 */
void *MEMmalloc(size_t size)
{
    void *ptr;

    DBUG_ASSERT((size >= 0), "called with negative size!");

    if (size > 0) {
        /*
        * Since some UNIX system (e.g. ALPHA) do return NULL for size 0 as well
        * we do complain for ((NULL == tmp) && (size > 0)) only!!
        */
        ptr = malloc(size);

        if (ptr == NULL) {
            CTIabortOutOfMemory(size);
        }
    }
    else {
        ptr = NULL;
    }

    return ptr;
}

/**
 * Allocate managed memory with a header containing extra details added in
 * @param size Amount to allocate.
 * @param type The memory type being allocated.
 * @return A pointer to an allocated structure.
 */
void *MEMmallocWithHeader(size_t size, enum mem_type type)
{
    /*
    * Allocate enough memory for the requested size
    * with a mem_header in front of it
    */
    struct mem_header *ptr = MEMmalloc(size + sizeof(struct mem_header));

    /* Set the mem_header values */
    ptr->mark = false;
    ptr->type = type;
    ptr->allocate_action_name = mem_manager.getCurrentActionName();
    printf("Allocation with header done from: %s\n", ptr->allocate_action_name);

    /* Add address to list of managed addresses */
    LLadd(mem_manager.allocations_list, ptr);

    /* Return the pointer to the memory after the header */
    return MEM_DATA(ptr);
}

/**
 * Free memory. Returns NULL, but allows to do assignment to freed structure.
 * @param address address to free.
 */
void *MEMfree(void *address)
{
    if(address != NULL) {
        free(address);
        address = NULL;
    }

    return address;
}

/**
 * Free managed memory.
 * Returns NULL, but allows to do assignment to freed structure.
 * @param address address to freed.
 */
void *MEMfreeWithHeader(void *address) {
    /* Remove address from list of managed addresses */
    LLremove(mem_manager.allocations_list, MEM_HEADER(address));

    /* Free memory, including header */
    return MEMfree(MEM_HEADER(address));
}

void *MEMcopy(size_t size, void *mem)
{
    void *result;

    result = MEMmalloc(size);
    result = memcpy(result, mem, size);

    return result;
}