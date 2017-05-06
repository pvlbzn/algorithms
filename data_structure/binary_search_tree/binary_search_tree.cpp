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

#include <cstddef>

#include "binary_search_tree.hpp"


/**
 * Full node factory
 *
 * @param  key
 * @param  parent
 * @param  left
 * @param  right
 * @return initialized node
 */
bst *factory(int key, int value, bst *left, bst *right)
{
    auto *node = new bst;

    node->key    = key;
    node->value  = value;
    node->left   = left;
    node->right  = right;

    return node;
}

/**
 * Key-value node factory
 *
 * @param key
 * @param value
 * @return initialized node
 */

/**
 * Empty node factory
 *
 * @return zero initialized node
 */
bst *factory()
{
    return factory(0, 0, NULL, NULL);
}


bool isBinarySearchTree(bst *node, int min, int max) {
    return false;
}


bool search(bst *node, int key)
{
    if (node == NULL) return false;
}

void insert(bst *node, int key, int value)
{
    if (node == NULL)
        node = factory(key, value);
}

void remove(bst *node, int key)
