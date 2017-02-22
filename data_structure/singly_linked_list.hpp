// Implementation as of CLRS book.
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

struct list_t
{
    struct node_t* head;
};

struct node_t
{
    int data;
    struct node_t* next;
};

void insert(list_t *list, node_t *node);
void insert(list_t *list, int key);

node_t* search(list_t *list, int key);

void remove(list_t *list, int key);
void remove(node_t *n, node_t *target);
