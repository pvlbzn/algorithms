#define CATCH_CONFIG_MAIN

#include "include/catch.hpp"
#include "../sort/counting_sort/counting_sort.hpp"


TEST_CASE("count sort must operate properly", "[CountSort]")
{
    SECTION("find k") {
        auto arr = new int[6]{83, 12, 9, 99, 10, 23};
        int k = CountingSort::find_k(arr, 6);
        REQUIRE(k == 99);
    }

    SECTION("sorting") {
        auto arr = new int[6]{83, 12, 0, 99, 10, 23};
        auto res = CountingSort::sort(arr, 6);

        int prev = 0;
        for (int i = 0; i < 6; i++) {
            REQUIRE(prev <= res[i]);
            prev = res[i];
        }
    }
    
}
