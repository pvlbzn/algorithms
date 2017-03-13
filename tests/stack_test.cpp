#define CATCH_CONFIG_MAIN

#include "include/catch.hpp"
#include "../data_structure/stack/stack.hpp"



TEST_CASE( "data can be pushed onto stack and poped out of it", "[stack_t]" )
{
    stack *s = stack_factory();

    push(s, 5);
    
    SECTION("pop from a stack", "[pop]") {
        REQUIRE(pop(s) == 5);
        REQUIRE(s->head == NULL);
    }

    SECTION("peek on a stack", "[peek]") {
        REQUIRE(peek(s) == 5);
    }
}
