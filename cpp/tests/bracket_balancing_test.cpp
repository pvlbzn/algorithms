#define CATCH_CONFIG_MAIN
#include <map>

#include "include/catch.hpp"
#include "../validation/bracket_balancing/bbalance.hpp"


TEST_CASE("bracket balancing must operate properly", "[Balancer]")
{
    std::map<std::string, std::string> valid_seq = {
        { "trivial", "{}" },
        { "long", "{{{{{{}}{{{{}}}}}}{{{{}}}}}}" },
        { "balanced", "{{{}{}}{}}" },
    };

    std::map<std::string, std::string> invalid_seq = {
        { "missing", "{{{}{}{}}" },
        { "extra", "{{{}{}}{}}}" },
        { "invalid", "{{}}{" },
    };

    SECTION("loop based balancer") {
        for (auto const& elem : valid_seq)
            REQUIRE(Balancer::validate(elem.second) == true);
        
        for (auto const& elem : invalid_seq)
            REQUIRE(Balancer::validate(elem.second) == false);
    }

    SECTION("reqursion based balancer") {
        for (auto const& elem : valid_seq)
            REQUIRE(Balancer::rec_validate(elem.second) == true);
        
        for (auto const& elem : invalid_seq)
            REQUIRE(Balancer::rec_validate(elem.second) == false);
    }
}
