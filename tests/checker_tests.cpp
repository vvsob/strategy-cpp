#include <catch2/catch_test_macros.hpp>
#include "strategy.h"

TEST_CASE( "checker works", "[checker]" ) {
    auto check = [](strategy::istream& input, strategy::istream& output, strategy::istream& answer, strategy::ostream& judgement) {
            return strategy::CheckerJudgement("ok", 1);
    };
    strategy::checker_main(1, {}, check);
}

