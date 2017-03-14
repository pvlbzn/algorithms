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
                REQUIRE(get(list, 2)->data == 3);
            }
            
            SECTION("get node with underflow") {
                REQUIRE(get(list, -5) == NULL);
            }

            SECTION("get node with overflow") {
                REQUIRE(get(list, 50) == NULL);
            }
        }

        SECTION("remove from the list") {
            remove(get(list, 1));
            REQUIRE(list->nil->data == 2);
        }

        SECTION("insert node at position") {
            node_t *node = node_factory();
            node->data = 0;
            insert(list, node, 0);

            REQUIRE((list->nil == node and list->nil->data == 0));
        } 

        SECTION("swap two nodes in the list") {
            node_t *middle = get(list, 1);
            node_t *last = get(list, 2);
            swap(list, middle, last);
            // Now list should be 1->3->2
            REQUIRE(list->nil->data == 1);
            REQUIRE(list->nil->next->data == 3);
            REQUIRE(list->nil->next->next->data == 2);
        }

    }

}
