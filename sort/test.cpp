// Collection of simple test suits.
//
// This test suite is used to write algorithms in a test driven development
// maneer.
//
// Pavel Bazin 2017

#include <assert.h>
#include <iostream>

#include "insertion_sort.hpp"
#include "../data_structure/singly_linked_list.hpp"


void insertion_sort_test();


int main()
{
    std::cout << "Running a test suit..." << std::endl;

    insertion_sort_test();

    std::cout << "PASS" << std::endl;
}


void insertion_sort_test()
{
    std::cout << "\tInsertion Sort test suite" << std::endl;

    // Integer array insertion sort
    int arr[] = { 5, 3, 9, 1, 4, 6 };
    unsigned int size = (sizeof(arr) / sizeof(*arr));

    insertion_sort(arr, size);

    assert((arr[0] == 1) && "1st item must has the value of 1");
    assert((arr[1] == 3) && "2nd item must has the value of 3");
    assert((arr[2] == 4) && "3rd item must has the value of 4");
    assert((arr[3] == 5) && "4th item must has the value of 5");
    assert((arr[4] == 6) && "5th item must has the value of 6");
    assert((arr[5] == 9) && "5th item must has the value of 9");


    // Linked list insertion sort
    list_t *list = list_factory();
    // Make a list { 6, 4, 1, 9, 3, 5 }
    insert(list, 5);
    insert(list, 3);
    insert(list, 9);
    insert(list, 1);
    insert(list, 4);
    insert(list, 6);

    // Test sort correctness
    insertion_sort_naive(list);

    assert((get_node(list, 0)->data == 1) && "1st item must has the value of 1");
    assert((get_node(list, 1)->data == 3) && "2nd item must has the value of 3");
    assert((get_node(list, 2)->data == 4) && "3rd item must has the value of 4");
    assert((get_node(list, 3)->data == 5) && "4th item must has the value of 5");
    assert((get_node(list, 4)->data == 6) && "5th item must has the value of 6");
    assert((get_node(list, 5)->data == 9) && "5th item must has the value of 9");


    // Prove that this solution is buggy and must be avoided:

    // Create a new list
    list_t *list_2 = list_factory();
    // Make a list { 6, 4, 1, 9, 3, 5 }
    insert(list_2, 5);
    insert(list_2, 3);
    insert(list_2, 9);
    insert(list_2, 1);
    insert(list_2, 4);
    insert(list_2, 6);

    node_t *node = get_node(list_2, 0);
    // Make sure that the right node was picked
    assert((node->data == 6) && "data must be 6");
    // Sort the list, it works correct because it was tested above
    insertion_sort_naive(list_2);
    assert((node->data == 1) && "data must be 1");


    std::cout << "\tPASS\n" << std::endl;
}