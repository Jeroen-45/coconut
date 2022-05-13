#pragma once

#include <stdlib.h>
#include <stdbool.h>


enum mem_type {
    MEM_TYPE_UNKNOWN,
    MEM_TYPE_NODE,
    MEM_TYPE_NODE_DATA,
    MEM_TYPE_STR
};

extern void MEMsetCurrentActionNameFunction(char *(*f)());
extern bool MEMgetTraversalInProgress();
extern void MEMsetTraversalInProgress(bool in_progress);
extern void MEMsetCurrentHandlerName(char *name);
extern void MEMmanagerInit();
extern void MEMmanagerCleanup();
extern void *MEMmalloc(size_t size);
extern void *MEMcalloc(size_t nitems, size_t size);
extern void *MEMmallocWithType(size_t size, enum mem_type type);
extern void *MEMfree(void *address);
extern void *MEMfreeWithHeader(void *address);
extern void *MEMcopy(size_t size, void *mem);
extern void MEMmark(void *address);
