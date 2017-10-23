#include "heap.hpp"
#include <algorithm>

int parent(int i)
{
    return (i - 1) / 2;
}


int left(int i)
{
    return 2 * i + 1;
}


int right(int i)
{
    return 2 * i + 2;
}


void heapify(int *arr, int len, int i)
{
    int l = left(i);
    int r = right(i);
    int largest = 0;

    if (l <= (len - 1) and arr[l] > arr[i]) largest = l;
    else largest = i;

    if (r <= (len - 1) and arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, len, largest);
    }
}


void build_heap(int *arr, int len)
{
    for (int i = (len / 2) - 1; i >= 0; i -= 1) heapify(arr, len, i);
}


void heapsort(int *arr, int len)
{
    build_heap(arr, len);

    for (int i = len - 1; i > 0; i -= 1) {
        std::swap(arr[0], arr[i]);
        heapify(arr, --len, 0);
    }
}