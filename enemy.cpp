#include "enemy.h"
#include <queue>
#include <vector>


Enemy::Enemy() : Enemy(0, 0) {}
Enemy::Enemy(int x,int y) : Square(x, y) {}

void Enemy::move(const Maze maze, const Square& player)
{
    Square newPos;
    newPos = getMove(maze, player);
    this->setX(newPos.getX());
    this->setY(newPos.getY());
}

Square Enemy::getMove(const Maze maze, const Square& player)
{
    // Transformations for moves up, right, down, left
    const int directionX[] = {-1, 0, 1, 0};
    const int directionY[] = {0, 1, 0, -1};

    int rows = maze.getSize();
    int cols = maze.getSize();

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> unchecked;
    std::vector<std::vector<bool>>   checked(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<int>>    gScore(rows, std::vector<int>(cols, INT_MAX));

    Node first(player.getX(), player.getY(), 0, 0, 0);
    gScore[player.getX()][player.getY()] = 0;
    unchecked.push(first);


    // A* Algorithm loop
    while (!unchecked.empty())
    {
        // Get square with lowest f-score
        Node current = unchecked.top();
        unchecked.pop();

        // Mark current square as checked
        checked[current.getX()][current.getY()] = true;

        // Search adjacent cells
        for (int i = 0; i < 4; ++i)
        {
            int newX = current.getX() + directionX[i];
            int newY = current.getY() + directionY[i];

            if(newX == this->getX() && newY == this->getY())
            {
                Square returnValue(current.getX(), current.getY());
                return returnValue;
            }

            // Check grid boundaries and walkability
            if ((newX >= 0 && newX < rows) && (newY >= 0 && newY < cols)
                && maze.isValidMove(newX, newY) == true)
            {
                if (checked[newX][newY]) continue;

                int newG = current.g + 1;               //BREAKPOINT

                if (newG < gScore[newX][newY])
                {
                    gScore[newX][newY] = newG;

                    // Compute new neighbor costs
                    Node neighbor(newX, newY);
                    neighbor.g = newG;
                    neighbor.h = std::abs(newX - player.getX()) + std::abs(newY - player.getY()); // Manhattan distance
                    neighbor.f = neighbor.g + neighbor.h;

                    // Add neighbor to open list for further exploration
                    unchecked.push(neighbor);
                }
            }
        }
    }
    
    //NO PATH (something went wrong)
    return(Square());
}