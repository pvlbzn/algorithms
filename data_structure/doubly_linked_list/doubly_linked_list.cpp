// Circular doubly linked list with a sentinel implementation.
//
// Pavel Bazin 2017

#include "doubly_linked_list.hpp"



/**
 * List factory
 *
 * List factory is a preffered way of creating a new list. In process
 * of initialization list is looped on itself, such that next and prev
 * pointers points to the list itself.
 *
 * Returns:
 *      null-initialized list
 */
list_t* list_factory()
{
    list_t *list = new list_t();

    list->nil = node_factory();
    list->nil->next = list->nil;
    list->nil->prev = list->nil;

    return list;
}


/**
 * Node factory
 *
 * Node factory is a preffered way of creating a new node.
 *
 * Returns:
 *      null-initialized node
 */
node_t* node_factory()
{
    node_t *node = new node_t();
    node->data = 0;
    node->next = NULL;
    node->prev = NULL;

    return node;
}


/**
 * Find key in a linked list.
 *
 * Complexity: O(n)
 *
 * Args:
 *      list: pointer to a lists's head
 *      key:  key to be found in a list
 *
 * Returns:
 *      pointer to a node which holds a `key` value
 */
node_t* search(list_t *head, int key)
{
    node_t *node = head->nil->next;

    while (node != head->nil and node->data != key)
        node = node->next;

    return node;
}


void insert(list_t *head, node_t *node)
{
    node->next = head->nil->next;
    head->nil->next->prev = node;
    head->nil->next = node;
    node->prev = head->nil;
}


void insert(list_t *head, node_t *node, int at)
{
    node_t *tmp = head->nil->next;

    for (int i = 0; i <= at; i += 1)
        tmp = tmp->next;

    node->next = tmp;
    node->prev = tmp->prev;
    tmp->prev->next = node;
    tmp->prev = node;
}


void insert(list_t *head, int key)
{
    node_t *node = node_factory();
    node->data = key;
    insert(head, node);
}


void insert(list_t *head, int key, int at)
{
    node_t *node = node_factory();
    node->data = key;
    insert(head, node, at);
}


void remove(node_t *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
}


node_t* get_node(list_t *head, int at)
{
    ; // implementation missing
}


void swap(list_t *head, node_t *a, node_t *b)
{
    ; // implementation missing
}


list_t* cut(list_t *head, int at)
{
    ; // implementation missing
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
int size(list_t *head)
{
    ; // implementation missing
}


std::string to_str(list_t *head)
{
    node_t *node = head->nil->next;
    std::string str = "[";

    while (node != head->nil) {
        node = node->next;
        str += std::to_string(node->prev->data);
        if (node != head->nil) str += ", ";
    }

    return str += "]";
}
