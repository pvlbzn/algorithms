// This implementation follows CLRS book in therminology and definitions,
// while implimentation may be different from a given pseudocode due to
// adaptation for particular language.
//
// Insertion-Sort(A)
//
// Pavel Bazin 2017

#include <cstdlib>
#include "insertion_sort.hpp"


/**
 * Insertion-Sort(A) implementation.
 * Sort an array of integers (in place).
 *
 * Args:
 *      arr:  pointer to the first item in array
 *      size: size of the array
 *
 * Complexity:
 *      searching: O(n)
 *      inserting: O(1)
 *      total:     O(n^2)
 *
 * Insertion sort loop invariant: left hand side array part is always sorted.
 * Let be A array of the size n, then A[1..j-1] represents sorted cards,
 * A[j-1..n] is left cards that have to be sorted. Moreover, A[1..j-1] elements
 * are the elements originaly from this slice area, but in a sorted order.
 */
void insertion_sort(int *arr, unsigned int size)
{
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}


/**
 * WARNING: DO NOT USE IT, DESIGNED FOR EDUCATIONAL PURPOSE.
 *
 * Insertion-Sort on linked list datatype implementation.
 *
 * Args:
 *      arr:  pointer to the first item in array
 *
 * Complexity:
 *      3n^3 + 2n^2 + n => O(n^3)
 *
 * Following approach is a direct adoptation of a routine which was designed
 * to process array data structure. This approach has two issues. First,
 * it has a very high time complexity. Second, and more important, it makes
 * side effects. It does a simple data rebinding which can lead to subtle bug
 * in a program. Consider:
 *      Let A be a list { 5, 1, 3 }
 *      node_t* node = get_node(A, 0);
 *      print(node->data);
 *      insertion_sort_naive(A);
 *      print(node->data);
 * First print function will produce "5", while the second one will produce
 * "1", which is the data violation.
 */
void insertion_sort_naive(list_t *list)
{
    for (int i = 1; i < size(list); i++) {
        int key = get_node(list, i)->data;
        int j = i - 1;
        while (j >= 0 && get_node(list, j)->data > key) {
            get_node(list, j + 1)->data = get_node(list, j)->data;
            j -= 1;
        }
        get_node(list, j + 1)->data = key;
    }
}


/**
 * Insertion-Sort on a linked list datatype implementation.
 *
 * Args:
 *      arr:  pointer to the first item in array
 *
 * Complexity: O(n^3)
 *
 * While complexity of this solution is better than the previous one (yet both
 * are O(n^3)), this solution provides correct data handling and does not
 * violate and corrupt the data.
 */
void insertion_sort(list_t *list)
{
    for (int i = 1; i < size(list); i++) {
        node_t *key_node = get_node(list, i);
        int j = i - 1;
        node_t *j_node;
        
        while (j >= 0 && ((j_node = get_node(list, j))->data) > key_node->data) {
            j -= 1;
            swap(list, key_node);
        }
    }
}
