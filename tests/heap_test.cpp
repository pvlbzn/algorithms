#define CATCH_CONFIG_MAIN

#include "include/catch.hpp"
#include "../data_structure/heap/heap.hpp"



TEST_CASE( "heap sort behaves accordingly to specification", "[heap]" )
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
}
