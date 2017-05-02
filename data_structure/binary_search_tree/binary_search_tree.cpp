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

#include <cstddef>

#include "binary_search_tree.hpp"

bst *search(bst *node, int target)
{
    // If tree is empty return NULL
    if (node == NULL) return NULL;

    // If we found a right key, return a node
    if (node->key == target) return node;

    // If target is bigger than current's node key
    if (target < node->key)
        return search(node->left, target);
    else
        return search(node->right, target);
}
