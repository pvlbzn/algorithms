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
    node_t *n = new node_t();
    n->data = key;

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
            delete node;
            return;
        } else if (node->data == key and prev != NULL) {
            prev->next = node->next;
            delete node;
            return;
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
 * To delete particular node, due to limitation of singly linked list, a node
 * fisrt must be found in a linked list. The procudure is very similar
 * to delete by key, but we can not do remove(target->data) because list
 * may contain n elements with the same data but on different addresses.
 */
void remove(list_t *list, node_t *target)
{
    node_t *prev = NULL;
    node_t *node = list->head;

    while (node != NULL) {
        if (node == target and prev == NULL) {
            list->head = node->next;
            delete target;
            return;
        } else if (node == target and prev != NULL) {
            prev->next = node->next;
            delete target;
            return;
        }

        prev = node;
        node = node->next;
    }
}


//
// Additional functionality, not defined in CLRS
//


/**
 * List factory
 *
 * List factory is a preffered way of creating a new list because of UB.
 *
 * Returns:
 *      null-initialized list
 */
list_t* list_factory()
{
    list_t *l = new list_t();
    l->head = NULL;

    return l;
}


/**
 * Node factory
 *
 * Node factory is a preffered way of creating a new node because of UB.
 *
 * Returns:
 *      null-initialized node
 */
node_t* node_factory()
{
    node_t *n = new node_t();
    n->data = 0;
    n->next = NULL;

    return n;
}


/**
 * Get node by index
 *
 * Complexity: O(n)
 *
 * Args:
 *      list: pointer to a lists's head
 *      pos:  position of the node
 *
 * Returns:
 *      pointer to the node in required position or NULL in case if node
 *      with such an index does't exists.
 */
node_t* get_node(list_t *list, int pos)
{
    node_t *node = list->head;

    for (int i = 0; i < pos; i++) {
        if (node == NULL) return NULL;
        node = node->next;
    }
    
    return node;
}


/**
 * Get size of a list
 *
 * Complexity: O(n)
 *
 * Args:
 *      list: pointer to a lists's head
 * 
 * Returns:
 *      size of the list
 */
int size(list_t *list)
{
    node_t *node = list->head;

    int size = 0;

    while (node != NULL) {
        node = node->next;
        size += 1;
    }

    return size;
}
