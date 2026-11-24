#include "square.h"

Square::Square() : Square(0,0) {} //default

Square::Square(int x, int y) : x(x), y(y) {}

int Square::getX() const
{
    return x;
}
int Square::getY() const
{
    return y;
}

bool Square::operator>(const Square& other) const
{
    return (f > other.f);
}
bool Square::operator==(const Square& other) const
{
    return (x == other.x && y == other.y);
}

bool Square::isOverlapped(const Square& other) const
{
    return (this->x== other.x && this->y == other.y);
}