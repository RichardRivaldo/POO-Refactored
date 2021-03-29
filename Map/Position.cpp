#include <iostream>
#include "Position.hpp"

using namespace std;

Position::Position()
{
    x = 0;
    y = 0;
}

Position::Position(int coordinate_x, int coordinate_y)
{
    x = coordinate_x;
    y = coordinate_y;
}

Position::Position(const Position &pos)
{
    x = pos.x;
    y = pos.y;
}

Position &Position::operator=(const Position &pos)
{
    x = pos.x;
    y = pos.y;
    return *this;
}

bool Position::operator==(const Position &pos) const
{
    return (x == pos.x && y == pos.y);
}
Position::~Position()
{
    //
}

int Position::getXCoordinate()
{
    return this->x;
}

int Position::getYCoordinate()
{
    return this->y;
}

void Position::setXCoordinate(int _x)
{
    x = _x;
}

void Position::setYCoordinate(int _y)
{
    y = _y;
}