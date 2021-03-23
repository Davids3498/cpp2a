#include <iostream>
#include "Board.hpp"
using namespace std;

namespace ariel
{
    void Board::post(uint row, uint col, Direction course, string const &msg)
    {
        cout << "posting message" << endl;
    }

    string Board::read(uint row, uint col, Direction course, uint charNum)
    {
        return "reading message";
    }

    void Board::show()
    {
        cout << "showing message" << endl;
    }

}