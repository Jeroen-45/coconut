#pragma once

#include <stdlib.h>


enum mem_type {
    MEM_TYPE_UNKNOWN,
    MEM_TYPE_NODE,
    MEM_TYPE_STR
};

extern void MEMsetCurrentActionNameFunction(char *(*f)());
extern void MEMmanagerInit();
extern void MEMmanagerCleanup();
extern void *MEMmalloc(size_t size);
extern void *MEMmallocWithHeader(size_t size, enum mem_type type);
extern void *MEMfree(void *address);
extern void *MEMfreeWithHeader(void *address);
extern void *MEMcopy(size_t size, void *mem);
