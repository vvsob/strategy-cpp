#include <catch2/catch_test_macros.hpp>
#include "strategy.h"

TEST_CASE( "random generates the same numbers", "[random]" ) {
    strategy::random rnd1(1), rnd2(1);

    REQUIRE(rnd1() == rnd2());
    REQUIRE(rnd1() == rnd2());
    REQUIRE(rnd1() == rnd2());
}
