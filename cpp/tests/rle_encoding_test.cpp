#define CATCH_CONFIG_MAIN

#include <string>

#include "include/catch.hpp"
#include "../encoding/rle/rle.hpp"



TEST_CASE( "RLE encoding test", "[RLE]" )
{

    std::string str = "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW";
    std::string enc = "12W1B12W3B24W1B14W";

    SECTION("encode data", "[RLE::encode]") {
        REQUIRE( RLE::encode(str).get_data() == enc );
        // REQUIRE( true );
    }

}
