#include <cstdlib>

#pragma once



/**
 * Circular doubly linked list with a sentinel. list_t appears to be between
 * the head and tail. nil.next is the first element of the linked list,
 * nil.prev is the last element in the linked list.
 */
struct list_t
{
    struct node_t* nil;
};


struct node_t
{
    int data;
    struct node_t* next;
    struct node_t* prev;
};


list_t* list_factory()
{
    list_t *list = new list_t();
    list->nil = NULL;
    
    return list;
}


node_t* node_factory()
{
    node_t *node = new node_t();
    node->data = 0;
    node->next = NULL;
    node->prev = NULL;

    return node;
}


node_t* search(list_t *head, int key);
void    insert(list_t *head, node_t *node);
void    insert(list_t *head, node_t *node, int at);
void    remove(list_t *head, node_t *node);
void    swap(list_t *head, node_t *a, node_t *b);
int     size(list_t *head);
