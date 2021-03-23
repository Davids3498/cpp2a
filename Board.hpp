#pragma once
#include <iostream>
#include <string>
#include "Direction.hpp"

namespace ariel
{
    class Board
    {
    public:
        Board() {}
        static void post(uint, uint, Direction, std::string const &);
        static std::string read(uint, uint, Direction, uint);
        static void show();
    };
}