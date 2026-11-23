#include "enemy.h"

Square::Square(int x, int y)
{
    this->x = x;
    this->y = y;
    this->f = 0;
    this->g = 0;
    this->h = 0;
}

bool Square::operator>(const Square& other) const
{
    return (f > other.f);
}


Square getMove(const Maze maze, const Square& enemy, const Square& player)
{
    // Transformations for moves up, right, down, left
    const int directionX[] = {-1, 0, 1, 0};
    const int directionY[] = {0, 1, 0, -1};

    int rows = maze.GetSize();
    int cols = maze.GetSize();

    // A* Algorithm loop
    



}

