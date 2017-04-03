#define CATCH_CONFIG_MAIN

#include "include/catch.hpp"
#include "../data_structure/heap/heap.hpp"



TEST_CASE( "heap should behave accordingly to specification", "[heap]" )
{
    int heap[10] { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
    
    SECTION("get parent", "[parent]") {
        REQUIRE( heap[parent(1)] == 16 );
        REQUIRE( heap[parent(5)] == 10 );
    }

    SECTION("get left node", "[left]") {
        REQUIRE( heap[left(1)] == 8 );
        REQUIRE( heap[left(2)] == 9 );
    }

    SECTION("get right node", "[right]") {
        REQUIRE( heap[right(1)] == 7 );
        REQUIRE( heap[right(2)] == 3 );
    }

    SECTION("heapify", "[heapify]") {
        int unheapified[10] { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };

        SECTION("heapify 2nd (i = 1) element", "[heapify]") {
            heapify(unheapified, 10, 1);
            
            for (int i = 0; i < 10; i += 1) REQUIRE(heap[i] == unheapified[i]);
        }
    }

    SECTION("build max heap must be correct", "[build_heap]") {
        int arr[10] { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

        build_heap(arr, 10);

        for (int i = 0; i < 10; i += 1) REQUIRE(heap[i] == arr[i]);
    }
}
