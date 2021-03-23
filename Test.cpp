#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"

using namespace std;

TEST_CASE("Board test")
{
    ariel::Board TestBoard;
    TestBoard.post(0, 0, ariel::Direction::Horizontal, "Hello World");

    CHECK(TestBoard.read(0, 0, ariel::Direction::Horizontal, 11) == "Hello World");
    CHECK(TestBoard.read(0, 0, ariel::Direction::Horizontal, 10) == "Hello Worl");
    CHECK(TestBoard.read(0, 1, ariel::Direction::Horizontal, 10) == "ello World");
    CHECK(TestBoard.read(0, 0, ariel::Direction::Horizontal, 0) == "");

    TestBoard.post(1, 0, ariel::Direction::Horizontal, " ");
    CHECK(TestBoard.read(0, 0, ariel::Direction::Vertical, 2) == "H ");
    CHECK(TestBoard.read(1, 1, ariel::Direction::Horizontal, 1) == "_");
    CHECK(TestBoard.read(1, 1, ariel::Direction::Vertical, 1) == "_");

    TestBoard.post(0, 4, ariel::Direction::Horizontal, "xyz");
    CHECK(TestBoard.read(0, 0, ariel::Direction::Horizontal, 11) == "Hellxyzorld");

    TestBoard.post(3, 3, ariel::Direction::Horizontal, "i posted a message");
    CHECK(TestBoard.read(0, 3, ariel::Direction::Vertical, 3) == "l_i");
    CHECK(TestBoard.read(3, 3, ariel::Direction::Horizontal, 18) == "i posted a message");
    CHECK(TestBoard.read(3, 0, ariel::Direction::Horizontal, 18) == "___i posted a mess");
    CHECK(TestBoard.read(3, 0, ariel::Direction::Horizontal, 21) == "___i posted a message");

    TestBoard.post(3, 15, ariel::Direction::Horizontal, "picture");
    CHECK(TestBoard.read(3, 3, ariel::Direction::Horizontal, 18) == "i posted a picture");

    TestBoard.post(0, 5, ariel::Direction::Vertical, "woosh");
    CHECK(TestBoard.read(3, 3, ariel::Direction::Horizontal, 18) == "i sosted a picture");
    CHECK(TestBoard.read(1, 4, ariel::Direction::Horizontal, 3) == "_o_");

    CHECK(TestBoard.read(4, 5, ariel::Direction::Horizontal, 1) == "k");
    CHECK(TestBoard.read(4, 5, ariel::Direction::Vertical, 2) == "sh");

    TestBoard.post(4, 0, ariel::Direction::Horizontal, "ayy is");
    TestBoard.post(5, 0, ariel::Direction::Horizontal, "waassh");
    CHECK(TestBoard.read(0, 5, ariel::Direction::Horizontal, 6) == "woossh");
    CHECK(TestBoard.read(1, 5, ariel::Direction::Vertical, 18) == "00");
    CHECK(TestBoard.read(5, 5, ariel::Direction::Horizontal, 2) == "h_");
}
