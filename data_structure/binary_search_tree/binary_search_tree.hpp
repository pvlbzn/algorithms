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
// Binary Tree Property:
//      Key in each node must be greater than or equal to any key stored
//      in the left sub-tree, and less than or equal to any key stored
//      in the right sub-tree.
//
// Pavel Bazin 2017


typedef struct bst {
    int key;
    int value;

    bst *left;
    bst *right;
} bst;


bool search(bst *t, int k);
void insert(bst *t, int k);
void remove(bst *t, int k);
