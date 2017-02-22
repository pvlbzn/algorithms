// This implementation follows CLRS book in therminology and definitions,
// while implimentation may be different from a given pseudocode due to
// adaptation for particular language.
// 
// Operations on dynamic sets:
//      Search(S, k)
//      Insert(S, x)
//      Delete(S, x)
//      Minimum(S)
//      Maximum(S)
//      Successor(S, x)
//      Predecessor(S, x)
//
// Operations on Linked List
//      List-Search(L, k)
//      List-Insert(L, x)
//      List-Delete(L, x)
//
// Pavel Bazin 2017


#include <cstdlib>

#include "singly_linked_list.hpp"

/**
 * List-Insert(L, k) implementation.
 * Inserts node with value key to a linked list.
 *
 * Complexity: O(1)
 *
 * Args:
 *      list: pointer to a list's head
 *      node: pointer to a node which must be inserted into a list 
 */
void insert(list_t *list, node_t *node)
{
    if (list->head != NULL)
        node->next = list->head;

    list->head = node;
}


/**
 * List-Insert(L, k) implementation.
 * Inserts node with value key to a linked list.
 *
 * Complexity: O(1)
 *
 * Args:
 *      list: pointer to a lists's head
 *      key:  value to be inserted into a list
 */
void insert(list_t *list, int key)
{
    node_t *n = (node_t*) std::malloc(sizeof(node_t));
    n->data = key;
    n->next = NULL;

    insert(list, n);
}


/**
 * List-Search(L, k) implementation.
 * Find key in a linked list.
 *
 * Complexity: O(n)
 *
 * Args:
 *      list: pointer to a lists's head
 *      key:  key to be found in a list
 */
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
 * List-Delete(L, x) implementation.
 * Remove element from a linked list by value.
 *
 * Complexity: O(n)
 *
 * Args:
 *      list: pointer to a lists's head
 *      key:  key to be removed from a list
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


/**
 * List-Delete(L, x) implementation.
 * Remove element from a linked list by value.
 *
 * Complexity: O(n)
 *
 * Args:
 *      list:   pointer to a lists's head
 *      target: reference to a node which must be deleted from a list
 *
 * To delete element x from the linked list the x's predecessor node's next
 * attribute must hold the pointer to x's successor node.
 *
 * However singly linked list has no pointer on predecessor node, therefore
 * there are no O(1) solution, but O(n) at worst case.
 */
void remove(node_t *n, node_t *target)
{
    ;
}
