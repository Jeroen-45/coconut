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
extern void MEMsetNodePrintFunc(void (*f)(void *));
extern bool MEMgetTraversalInProgress();
extern void MEMsetTraversalInProgress(bool in_progress);
extern void MEMsetMarkSpeculative(int mark_speculative);
extern char *MEMgetCurrentHandlerName();
extern void MEMsetCurrentHandlerName(char *name);
extern bool MEMdoLeakDetection();
extern bool MEMdoLeakDetectionBetweenHandlers();
extern void MEMincrementHandlerNestingLevel();
extern void MEMdecrementHandlerNestingLevel();
extern void MEMmanagerInit();
extern void MEMmanagerCleanup();
extern void *MEMmalloc(size_t size);
extern void *MEMmallocUnmanaged(size_t size);
extern void *MEMcalloc(size_t nitems, size_t size);
extern void *MEMcallocUnmanaged(size_t nitems, size_t size);
extern void *MEMmallocWithType(size_t size, enum mem_type type);
extern void *MEMfree(void *address);
extern void *MEMfreeWithHeader(void *address);
extern void *MEMcopy(size_t size, void *mem);
extern void MEMmark(void *address);
extern void MEMcheck();
