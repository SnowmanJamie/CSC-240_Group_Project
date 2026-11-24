/***************************************************************************************
* The code for the enemy class (primarily in the A* implementation) relies heavily upon
  the works povided on GitHub by the following source:

*    Title: A-Star-Pathfinding
*    Author: JDSherbert
*    Date: 2024
*    Availability: www.github.com/JDSherbert/A-Star-Pathfinding
***************************************************************************************/

#ifndef ENEMY_H
#define ENEMY_H

#include "square.h"
#include "maze.h"

struct Node : Square
{
    int f;
    int g;
    int h;

    Node(int x, int y, int f, int g, int h) : Square(x, y)
    {
        this->f = f;
        this->g = g;
        this->h = h;
    }
    Node(int x, int y) : Node(x, y, 0, 0, 0) {}
    Node() : Node(0, 0) {}

    // Func: Returns if f value of this is greater than f value of other
    // Pre:  This and other are initialized
    bool operator>(const Node& other) const
    {
        return (this->f > other.f);
    }
};

class Enemy : public Square
{
public:
    Enemy();
    Enemy(int x,int y);

    void move(const Maze maze, const Square& player);
    Square getMove(const Maze maze, const Square& player);
};


#endif