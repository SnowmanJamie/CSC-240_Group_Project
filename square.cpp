#include "square.h"

Square::Square() : Square(0,0) {} //default
Square::Square(int x, int y) : x(x), y(y) {} //parameterized

int Square::getX() const
{
    return x;
}
void Square::setX(const int x)
{
    this->x = x;
}
int Square::getY() const
{
    return y;
}
void Square::setY(const int y)
{
    this->y = y;
}

bool Square::operator==(const Square& other) const
{
    return (x == other.x && y == other.y);
}