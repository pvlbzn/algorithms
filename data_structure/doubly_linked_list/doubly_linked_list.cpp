// Implementation of circular doubly linked list with a sentinel.
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

    if (node == head->nil) return NULL;

    return node;
}


/**
 * Insert new node at the beginning of the list.
 *
 * Complexity: O(1)
 *
 * Args:
 *      head: pointer to the head of list (sentinel)
 *      node: pointer to a newly created node which will be inserted
 */
void insert(list_t *head, node_t *node)
{
    node->next = head->nil->next;
    head->nil->next->prev = node;
    head->nil->next = node;
    node->prev = head->nil;
}


/**
 * Insert new node at the position.
 *
 * Complexity: O(1)
 *
 * Args:
 *      head: pointer to the head of list (sentinel)
 *      node: pointer to a newly created node which will be inserted
 *      at:   position
 */
void insert(list_t *head, node_t *node, int at)
{
    node_t *tmp = head->nil->next;

    for (int i = 0; i < at; i += 1)
        tmp = tmp->next;

    node->next = tmp;
    node->prev = tmp->prev;
    tmp->prev->next = node;
    tmp->prev = node;
}


/**
 * Insert new node at the beginning of the list with a given key.
 *
 * Complexity: O(1)
 *
 * Args:
 *      head: pointer to the head of list (sentinel)
 *      key:  new node's value
 */
void insert(list_t *head, int key)
{
    node_t *node = node_factory();
    node->data = key;
    insert(head, node);
}


/**
 * Insert new node at the position 'at' with a given key.
 *
 * Complexity: O(1)
 *
 * Args:
 *      head: pointer to the head of list (sentinel)
 *      key:  new node's value
 *      at:   position
 */
void insert(list_t *head, int key, int at)
{
    node_t *node = node_factory();
    node->data = key;
    insert(head, node, at);
}


/**
 * Remove node from the list.
 *
 * Complexity: O(1)
 *
 * Args:
 *      node: pointer to the node which will be deleted
 */
void remove(node_t *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
}


/**
 * Get node at position.
 *
 * Complexity: O(1)
 *
 * Args:
 *      head: pointer to the head of list (sentinel)
 *      at:   position
 *
 * Returns:
 *      node from 'at' position
 */
node_t* get_node(list_t *head, int at)
{
    node_t *node = head->nil->next;

    while (node != head->nil and at != 0) {
        at -= 1;
        node = node->next;
    }

    if (at == 0 and node != head->nil) return node;
    else return NULL;
}


bool are_neighbours(node_t *a, node_t *b)
{
    return a->next == b or b->next == a ? true : false;
}


/**
 * Swap two nodes.
 *
 * Complexity: O(1)
 *
 * Args:
 *      a: first node
 *      b: second node
 */
void swap(node_t *a, node_t *b)
{
    a->prev->next = b;
    b->next->prev = a;

    node_t *anext = a->next;
    node_t *aprev = a->prev;
    node_t *bnext = b->next;
    node_t *bprev = b->prev;

    if (are_neighbours(a, b)) {
        a->next = b->next;
        b->next = a;

        a->prev = b->prev;
        b->prev = aprev;
    } else {
        aprev->next = b;
        b->next = anext;
        b->prev = aprev;
        anext->prev = b;

        bprev->next = a;
        a->next = bnext;
        a->prev = bprev;
        bnext->prev = a;
    }
}


/**
 * Get size of a list
 *
 * Complexity: 𝛩(n)
 *
 * Args:
 *      list: pointer to a lists's head
 *
 * Returns:
 *      size of the list
 */
int size(list_t *head)
{
    node_t *tmp;
    int i = 0;

    for (tmp = head->nil->next; tmp != head->nil; tmp = tmp->next) {
        i += 1;
    }

    return i;
}


/**
 * Format list as a string.
 *
 * Complexity: 𝛩(n)
 *
 * Args:
 *      head: pointer to the head of list (sentinel)
 *
 * Returns:
 *      string with formatting "[a1, a2, .., aN]"
 */
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
