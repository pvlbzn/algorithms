#define CATCH_CONFIG_MAIN

#include "include/catch.hpp"
#include "../data_structure/doubly_linked_list/doubly_linked_list.hpp"



TEST_CASE("list must operate accordingly to specification", "[list_t]")
{
    list_t *list = list_factory();

    SECTION("insert elements in list") {
        // Make 1->2->3 list
        insert(list, 3);
        insert(list, 2);
        insert(list, 1);
        
        REQUIRE(list->nil->next->data == 1);
        REQUIRE(list->nil->next->next->data == 2);
        REQUIRE(list->nil->next->next->next->data == 3);
    }

    insert(list, 3);
    insert(list, 2);
    insert(list, 1);

    SECTION("to_str function test") {
        REQUIRE(to_str(list) == "[1, 2, 3]");
    }

    SECTION("seach element in the list") {
        REQUIRE(search(list, 1)->data == 1);
        REQUIRE(search(list, 2)->data == 2);
        REQUIRE(search(list, 3)->data == 3);
    }

    SECTION("search non-existent element in the list") {
        REQUIRE(search(list, 15) == NULL);
    }

    SECTION("get list's size") {
        REQUIRE(size(list) == 3);
    }

    SECTION("get node from the list") {
        SECTION("get valid node index") {
            REQUIRE(get_node(list, 2)->data == 3);
        }

        SECTION("get first node") {
            REQUIRE(get_node(list, 0)->data == 1);
        }

        SECTION("get node with underflow") {
            REQUIRE(get_node(list, -5) == NULL);
        }

        SECTION("get node with overflow") {
            REQUIRE(get_node(list, 50) == NULL);
        }
    }

    SECTION("remove from the list") {
        // Should be nil-> 1 -> 3 -> nil
        remove(get_node(list, 1));
        REQUIRE(list->nil->next->data == 1);
        REQUIRE(list->nil->next->next->data == 3);
    }

    SECTION("insert node at position") {
        insert(list, 13, 0);

        REQUIRE(list->nil->next->data == 13);
        REQUIRE(list->nil->next->next->data == 1);
    }

    SECTION("swap two neighbour nodes in the list") {
        node_t *middle = get_node(list, 1);
        REQUIRE(middle->data == 2);

        node_t *last   = get_node(list, 2);
        REQUIRE(last->data == 3);

        swap(middle, last);

        // Now list should be 1->3->2
        REQUIRE(list->nil->next->data == 1);
        REQUIRE(list->nil->next->next->data == 3);
        REQUIRE(list->nil->next->next->next->data == 2);
    }

    SECTION("swap two nodes in the list") {
        insert(list, 4);
        
        REQUIRE(to_str(list) == "[4, 1, 2, 3]");

        swap(get_node(list, 0), get_node(list, 3));

        REQUIRE(list->nil->next->data == 3);
        REQUIRE(list->nil->prev->data == 4);
        REQUIRE(to_str(list) == "[3, 1, 2, 4]");
    }

}
