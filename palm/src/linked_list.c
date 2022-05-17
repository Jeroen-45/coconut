/**
 * PREFIX: LL
 */

#include <stdlib.h>
#include <stdbool.h>
#include "palm/linked_list.h"

#include "palm/memory.h"

struct linked_list_entry {
    void *data;
    struct linked_list_entry *next;
};

struct linked_list {
    struct linked_list_entry *first;
};

/**
 * Create a new linked list.
 */
struct linked_list *LLnew() {
    struct linked_list *ll = MEMmalloc(sizeof(struct linked_list));
    ll->first = NULL;
    return ll;
}

/**
 * Frees all entries and the linked list itself.
 * @param ll The linked list to delete.
 */
void LLdelete(struct linked_list *ll) {
    struct linked_list_entry *entry = ll->first;
    while (entry != NULL) {
        struct linked_list_entry *next = entry->next;
        MEMfree(entry);
        entry = next;
    }
    MEMfree(ll);
}

/**
 * Add a new entry to the linked list.
 * @param ll The linked list to add to.
 * @param data The data to add.
 */
void LLadd(struct linked_list *ll, void *data) {
    struct linked_list_entry *entry = MEMmalloc(sizeof(struct linked_list_entry));
    entry->data = data;
    entry->next = ll->first;
    ll->first = entry;
}

/**
 * Remove an entry from the linked list.
 * @param ll The linked list to remove from.
 * @param data The data to remove.
 * @return true if the entry was found and removed, false otherwise.
 */
bool LLremove(struct linked_list *ll, void *data) {
    struct linked_list_entry *entry = ll->first;
    struct linked_list_entry *prev = NULL;
    while (entry != NULL) {
        if (entry->data == data) {
            if (prev == NULL) {
                ll->first = entry->next;
            } else {
                prev->next = entry->next;
            }
            MEMfree(entry);
            return true;
        }
        prev = entry;
        entry = entry->next;
    }

    return false;
}

/**
 * Checks if the linked list contains the data.
 * @param ll The linked list to search through.
 * @param data The data to search for.
 * @return true if the data is found, false otherwise.
 */
bool LLin(struct linked_list *ll, void *data) {
    struct linked_list_entry *entry = ll->first;
    while (entry != NULL) {
        if (entry->data == data) {
            return true;
        }
        entry = entry->next;
    }
    return false;
}

/**
 * Iterate through the linked list and run the given function on each entry.
 */
void LLiterate(struct linked_list *ll, void (*func)(void *)) {
    struct linked_list_entry *entry = ll->first;
    while (entry != NULL) {
        func(entry->data);
        entry = entry->next;
    }
}