// Circular doubly linked list with a sentinel implementation.
//
// Pavel Bazin 2017

#include "doubly_linked_list.hpp"



list_t* list_factory()
{
    list_t *list = new list_t();
    
    list->nil = node_factory();
    list->nil->next = list->nil;
    list->nil->prev = list->nil;
    
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

    for (int i = 0; i < at; i += 1)
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


void remove(list_t *head, node_t *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
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