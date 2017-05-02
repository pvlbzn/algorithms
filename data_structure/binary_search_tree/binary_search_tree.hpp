// Binary Search Tree
// Reference:
//      https://en.wikipedia.org/wiki/Binary_search_tree
//
// Complexity:
//      Time:
//          Search: O(logn)
//          Insert: O(logn)
//          Delete: O(logn)
//      Space: O(n)
//
// Pavel Bazin 2017


typedef struct bst {
    int key;
    bst *parent;
    bst *left;
    bst *right;
} bst;

bst *search(bst *t, int k);
void insert(bst *t, int k);
void remove(bst *t, int k);
