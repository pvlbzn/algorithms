#define CATCH_CONFIG_MAIN

#include "include/catch.hpp"
#include "../data_structure/singly_linked_list/singly_linked_list.hpp"



TEST_CASE("list must operate accordingly to specification", "[list_t]")
{
    list_t *list = list_factory();

    SECTION("insert elements in list") {
        // Make 1->2->3 list
        insert(list, 3);
        insert(list, 2);
        insert(list, 1);

        REQUIRE(list->head->data == 1);
        REQUIRE(list->head->next->data == 2);
        REQUIRE(list->head->next->next->data == 3);

        SECTION("seach element in the list") {
            REQUIRE(search(list, 1)->data == 1);
            REQUIRE(search(list, 2)->data == 2);
            REQUIRE(search(list, 3)->data == 3);
        }

        SECTION("search non-existent element in the list") {
            REQUIRE(search(list, 15) == NULL);
        }

        SECTION("remove from the list") {
            remove(list, 1);
            REQUIRE(list->head->data == 2);
        }

        SECTION("get list's size") {
            REQUIRE(size(list) == 3);
        }

        SECTION("get node from the list") {
            SECTION("get valid node index") {
                REQUIRE(get_node(list, 2)->data == 3);
            }
            
            SECTION("get node with underflow") {
                REQUIRE(get_node(list, -5) == NULL);
            }

            SECTION("get node with overflow") {
                REQUIRE(get_node(list, 50) == NULL);
            }
        }

        SECTION("insert node at position") {
            node_t *node = node_factory();
            node->data = 0;
            insert(list, 0, node);

            REQUIRE((list->head == node and list->head->data == 0));
        } 

        SECTION("swap two nodes in the list") {
            node_t *last = get_node(list, 2);
            swap(list, last);
            // Now list should be 1->3->2
            REQUIRE(list->head->data == 1);
            REQUIRE(list->head->next->data == 3);
            REQUIRE(list->head->next->next->data == 2);
        }

    }

}
