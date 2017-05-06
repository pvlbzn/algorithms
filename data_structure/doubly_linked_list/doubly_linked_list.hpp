// Circular doubly linked list with a sentinel implementation.
//
// Pavel Bazin 2017

#include <string>


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


list_t* list_factory();
node_t* node_factory();

node_t* search(list_t *head, int key);
node_t* get_node(list_t *head, int at);
void    insert(list_t *head, node_t *node);
void    insert(list_t *head, int key);
void    insert(list_t *head, node_t *node, int at);
void    insert(list_t *head, int key, int at);
void    remove(node_t *node);
void    swap(list_t *head, node_t *a, node_t *b);
list_t* cut(list_t *head, int at);
int     size(list_t *head);

std::string to_str(list_t *head);
