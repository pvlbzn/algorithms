// This implementation follows CLRS book in therminology and definitions,
// while implimentation may be different from a given pseudocode due to
// adaptation for particular language.
// 
// Insertion-Sort(A)
//
// Pavel Bazin 2017

#include "insertion_sort.hpp"


/**
 * Insertion-Sort(A) implementation.
 * Sort an array of integers (in place).
 *
 * Complexity:
 *      searching: O(n)
 *      inserting: O(1)
 *      total:     O(n^2)
 *
 * Args:
 *      arr:  pointer to the first item in array
 *      size: size of the array
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
