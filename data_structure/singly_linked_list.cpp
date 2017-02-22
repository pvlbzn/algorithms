// Implementation as of CLRS book 

#include <cstdlib>

#include "singly_linked_list.hpp"

// Insert a new node by reference
void insert(list_t *list, node_t *node)
{
    if (list->head != NULL)
        node->next = list->head;

    list->head = node;
}


// Insert a new node by value
void insert(list_t *list, int key)
{
    node_t *n = (node_t*) std::malloc(sizeof(node_t));
    n->data = key;
    n->next = NULL;

    insert(list, n);
}


// Linear search in list
node_t* search(list_t *list, int key)
{
    node_t *node = list->head;

    while (node != NULL) {
        if (node->data == key)
            return node;
        else
            node = node->next;
    }

    return NULL;
}


/**
 * Remove element from linked list by value
 *
 * To delete element x from the linked list the x's predecessor node's next
 * attribute must hold the pointer to x's successor node.
 *
 * However singly linked list has no pointer on predecessor node, therefore
 * there are no O(1) solution, but O(n) at worst case.
 */
void remove(list_t *list, int key)
{
    node_t *prev = NULL;
    node_t *node = list->head;

    while (node != NULL) {
        if (node->data == key and prev == NULL) {
            list->head = node->next;
            std::free(node);
        } else if (node->data == key and prev != NULL) {
            prev->next = node->next;
            std::free(node);
        }

        prev = node;
        node = node->next;
    }
}


// Remove element from linked list by reference
void remove(node_t *n, node_t *target)
{
    ;
}
