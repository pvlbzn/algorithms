#include "doubly_linked_list.hpp"



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
