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

#include "maze.h"

struct Square
{
    int x; //x-coord
    int y; //y-coord
    int f; //g+h
    int g; //number of moves to square
    int h; //distance of square to player

    Square(int x=0, int y=0); //constructor
    bool operator>(const Square& other) const;
    bool operator==(const Square& other) const;

};

bool isOverlapped(const Square& other);

Square getMove(const Maze maze, const Square& enemy, const Square& player);


#endif