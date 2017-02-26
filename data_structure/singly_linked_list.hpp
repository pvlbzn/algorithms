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
void remove(list_t *list, node_t *target);


// Helper factory functions, not defined in CLRS
list_t* list_factory();
node_t* node_factory();

// Access function
node_t* get_node(list_t *list, int pos);
int size(list_t *list);
