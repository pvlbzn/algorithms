#include "counting_sort.hpp"

int* CountingSort::sort(int* in, int len) {
    int k = find_k(in, len);
    auto res = new int[len]();
    auto tmp = new int[k+1];

    for (int i = 0; i < len; i++) {
        tmp[in[i]] += 1;
    }

    int counter = 0;
    for (int i = 0; i < k+1; i++) {
        while (tmp[i]) {
            res[counter] += i;
            tmp[i]       -= 1;
            counter      += 1;
        }
    }

    delete[] tmp;

    return res;
}

// Find k, k represents a range of numbers.
//
// Here is a possible space optimization. If for example input array contains
// two numbers {1000, 1001}, then algorithm will allocate 1001 integers, instead
// of just two.
int CountingSort::find_k(int* in, int len) {
    int k = 0;

    for (int i = 0; i < len; i++)
        k = k < in[i] ? in[i] : k;
    
    return k;
}