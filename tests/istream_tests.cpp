#include <catch2/catch_test_macros.hpp>
#include "strategy.h"

TEST_CASE( "istream methods work", "[istream]" ) {
    std::string s = "123 12\n1";
    std::stringbuf stringbuf(s);

    strategy::istream cin(&stringbuf);
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
    std::string s = "1234567890 -1234567890\n";
    std::stringbuf stringbuf(s);

    strategy::istream cin(&stringbuf);
    auto x = cin.readLongLong(-1234567890, 1234567890);
    cin.readSpace();
    auto y = cin.readLongLong();
    cin.readEOL();
    cin.readEOF();
    REQUIRE(x == 1234567890);
    REQUIRE(y == -1234567890);
}

TEST_CASE( "istream readWord works", "[istream]" ) {
    std::string s = "Hello, World!";
    std::stringbuf stringbuf(s);

    strategy::istream cin(&stringbuf);
    auto x = cin.readWord();
    cin.readSpace();
    auto y = cin.readWord("W[a-z]{4}!");
    cin.readEOF();
    REQUIRE(x == "Hello,");
    REQUIRE(y == "World!");
}

TEST_CASE("istream read works", "[istream]") {
    std::string s = "Hello, World!";
    std::stringbuf stringbuf(s);

    strategy::istream cin(&stringbuf);
    REQUIRE(cin.read() == s);
}
