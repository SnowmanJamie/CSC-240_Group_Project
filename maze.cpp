
#include "maze.h"
#include <iostream>

// Constructor
Maze::Maze()
{
    grid = {
        "#########",
        "#S......#",
        "#.###.#.#",
        "#...#.#.#",
        "###.#...#",
        "#.....#E#",
        "#########"
    };
}

// Display the maze
void Maze::display() const
{
    for (const std::string& row : grid)
    {
        std::cout << row << std::endl;
    }
}

// Check if a move is valid
bool Maze::isValidMove(int x, int y) const
{
    if (y < 0 || y >= static_cast<int>(grid.size()))
        return false;

    if (x < 0 || x >= static_cast<int>(grid[y].size()))
        return false;

    return grid[y][x] != '#';
}

// Check if the player reached the exit
bool Maze::isExit(int x, int y) const
{
    if (!isValidMove(x, y))
        return false;

    return grid[y][x] == 'E';
}
