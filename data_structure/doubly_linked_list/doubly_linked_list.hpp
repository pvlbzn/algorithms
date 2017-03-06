
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

node_t* search(list_t *head, int key);
void    insert(list_t *head, node_t *node);
void    remove(list_t *head, node_t *node);
