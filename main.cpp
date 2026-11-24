// Main file
// Added Nov 8, 2026
// There's nothing in here, this was written in a text editor, it hasn't even been tested yet.

#include <iostream>
#include "Player.h"
#include "enemy.h"
#include "maze.h"

using namespace std;

int main()
{
  Square enemy{1, 1};
  Square player{5, 5};
  Maze testMaze;

  while(enemy.x != player.x && enemy.y != player.y)
  Square move = getMove(testMaze, enemy, player);
  cout << "(" << move.x << "," << move.y << ")" << endl;

  return 0;
}
