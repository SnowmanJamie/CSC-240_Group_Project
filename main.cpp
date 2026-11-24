// Main file
// Added Nov 8, 2026
// There's nothing in here, this was written in a text editor, it hasn't even been tested yet.

#include <iostream>
#include "square.h"
#include "enemy.h"
#include "maze.h"

using namespace std;

int main()
{
  Enemy enemy(1,1);
  Square player(5, 5);
  Maze testMaze;

  while(!(enemy == player))
  {
    enemy.move(testMaze, player);
    cout << "(" << enemy.getX() << "," << enemy.getY() << ")" << endl;
  }

  return 0;
}
