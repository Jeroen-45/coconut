#include "palm/memory.h"

#include <stdlib.h>
#include <string.h>

#include "palm/dbug.h"
#include "palm/ctinfo.h"
#include "palm/str.h"


struct mem_header {
    bool mark;
    enum mem_type type;
    char *allocate_action_name;
};

/* Set default function getCurrentActionName */
char *actionNameUnknown() {
    return STRcpy("Unknown");
}
char *(*getCurrentActionName)() = actionNameUnknown;

/**
 * Set the Current Action Name Function object
 * @param f The function to be used for retrieving the current action name
 */
void MEMsetCurrentActionNameFunction(char *(*f)()) {
    getCurrentActionName = f;
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
    ptr->allocate_action_name = getCurrentActionName();
    printf("Allocation with header done from: %s\n", ptr->allocate_action_name);

    /* Add address to list of managed addresses */
    // TODO

    /* Return the pointer to the memory after the header */
    return (void *)ptr + sizeof(struct mem_header);
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
    // TODO

    /* Free memory, including header */
    return MEMfree(address - sizeof(struct mem_header));
}

void *MEMcopy(size_t size, void *mem)
{
    void *result;

    result = MEMmalloc(size);
    result = memcpy(result, mem, size);

    return result;
}