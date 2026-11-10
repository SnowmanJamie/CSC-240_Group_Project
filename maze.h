
#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>

class Maze
{
public:
    // Pre: None
    // Post: Creates a maze with a starting layout
    Maze();

    // Pre: None
    // Post: Displays the current maze
    void display() const;

    // Pre: x and y represent coordinates to check
    // Post: Returns true if the position is inside the maze
    //       and is not a wall
    bool isValidMove(int x, int y) const;

    // Pre: x and y represent coordinates to check
    // Post: Returns true if the position is the exit
    bool isExit(int x, int y) const;

private:
    std::vector<std::string> grid;
};

#endif
