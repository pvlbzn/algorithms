#include <iostream>

#include "doubly_linked_list/doubly_linked_list.hpp"


int main()
{
    list_t *list = list_factory();
    insert(list, 5);
    insert(list, 2);
    insert(list, 9);

    std::cout << list->nil->next->data << std::endl;
    std::cout << list->nil->next->next->data << std::endl;
    std::cout << list->nil->next->next->next->data << std::endl;
    std::cout << to_str(list) << std::endl;
}