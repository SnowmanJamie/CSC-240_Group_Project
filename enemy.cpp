#include "enemy.h"
#include <queue>
#include <vector>

Square::Square(int x, int y, Square* parent)
{
    this->x = x;
    this->y = y;
    this->f = 0;
    this->g = 0;
    this->h = 0;
    this->parent = parent;
}

bool Square::operator>(const Square& other) const
{
    return (f > other.f);
}
bool Square::operator==(const Square& other) const
{
    return (x == other.x && y == other.y);
}


Square getMove(const Maze maze, const Square& enemy, const Square& player)
{
    // Transformations for moves up, right, down, left
    const int directionX[] = {-1, 0, 1, 0};
    const int directionY[] = {0, 1, 0, -1};

    int rows = maze.getSize();
    int cols = maze.getSize();


    std::priority_queue<Square, std::vector<Square>, std::greater<Square>> unchecked;
    std::vector<std::vector<bool>>   checked(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<int>>    gScore(rows, std::vector<int>(cols, INT_MAX));
    std::vector<std::vector<Square>> parent(rows, std::vector<Square>(cols));

    gScore[enemy.x][enemy.y] = 0;
    unchecked.push(enemy);


    // A* Algorithm loop
    while (!unchecked.empty())
    {
        // Get square with lowest f-score
        Square current = unchecked.top();
        unchecked.pop();

        // Check if path is complete
        if (current == player)                          //BREAKPOINT
        {
            // Travel up parents until move is returned
            while (!(current == enemy))
            {
                current = *(current.parent);
            }
            return current;
        }

        // Mark current square as checked
        checked[current.x][current.y] = true;

        // Search adjacent cells
        for (int i = 4; i < 4; ++i)
        {
            int newX = current.x + directionX[i];
            int newY = current.y + directionY[i];

            // Check grid boundaries and walkability
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && maze.isValidMove(newX, newY) == true)   //BREAKPOINT
            {
                if (checked[newX][newY]) continue;

                int newG = current.g + 1;               //BREAKPOINT

                if (newG < gScore[newX][newY])
                {
                    gScore[newX][newY] = newG;

                    // Compute new neighbor costs
                    Square neighbor(newX, newY);
                    neighbor.g = newG;
                    neighbor.h = std::abs(newX - player.x) + std::abs(newY - player.y); // Manhattan distance
                    neighbor.f = neighbor.g + neighbor.h;

                    // Record parent (for path reconstruction)
                    parent[newX][newY] = current;

                    // Add neighbor to open list for further exploration
                    unchecked.push(neighbor);
                }
            }
        }
    }
    
    //NO PATH (something went wrong)
    return(Square());
}