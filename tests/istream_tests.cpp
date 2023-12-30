#include <catch2/catch_test_macros.hpp>
#include "strategy.h"

TEST_CASE( "istream methods work", "[istream]" ) {
    std::stringstream str("123 12\n1");

    strategy::istream cin(str.rdbuf());
    int x = cin.readInt();
    cin.readSpace();
    int y = cin.readInt();
    cin.readEOL();
    int z = cin.readInt(1, 10);
    cin.readEOF();
    REQUIRE(x == 123);
    REQUIRE(y == 12);
    REQUIRE(z == 1);
}

TEST_CASE( "istream readLongLong works", "[istream]" ) {
    std::stringstream str("1234567890 -1234567890\n");

    strategy::istream cin(str.rdbuf());
    auto x = cin.readLongLong(-1234567890, 1234567890);
    cin.readSpace();
    auto y = cin.readLongLong();
    cin.readEOL();
    cin.readEOF();
    REQUIRE(x == 1234567890);
    REQUIRE(y == -1234567890);
}

TEST_CASE( "istream readWord works", "[istream]" ) {
    std::stringstream str("Hello, World!");

    strategy::istream cin(str.rdbuf());
    auto x = cin.readWord();
    cin.readSpace();
    auto y = cin.readWord("W[a-z]{4}!");
    cin.readEOF();
    REQUIRE(x == "Hello,");
    REQUIRE(y == "World!");
}

