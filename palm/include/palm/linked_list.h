#pragma once

#include <stdbool.h>

typedef struct linked_list linked_list_st;
linked_list_st *LLnew();
void LLdelete(linked_list_st *ll);
void LLadd(linked_list_st *ll, void *data);
bool LLremove(linked_list_st *ll, void *data);
bool LLin(struct linked_list *ll, void *data);
