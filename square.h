#ifndef
#define SQUARE_H

class Square
{
    int x; //x-coord
    int y; //y-coord
    int f; //g+h
    int g; //number of moves to square
    int h; //distance of square to player

    Square(int x=0, int y=0); //constructor

    getX() const;
    getY() const;


    bool operator>(const Square& other) const;
    bool operator==(const Square& other) const;
    bool isOverlapped(const Square& other);
};


#endif