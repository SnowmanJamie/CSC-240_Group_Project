#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
    // Func: Default constructor for Square
    // Pre:  Square is not initialized
    // Post: Square is initialized with x=0, y=0
    Square();
    // Func: Paramaterized constructor for Square
    // Pre:  Square is not initialized
    // Post: Square is initialized with x=x, y=y
    Square(int x, int y); //constructor

    // Func: Returns x
    int getX() const;
    // Func: Returns y
    int getY() const;
    
    // Func: Returns if f value of this is greater than f value of other
    // Pre:  This and other are initialized with values of f
    bool operator>(const Square& other) const;
    // Func: Returns if f value of this is equal to f value of other
    // Pre:  This and other are initialized with values of f
    bool operator==(const Square& other) const;
    // Func: Returns if this and other share the same x and y values
    // Pre:  Both this and other anre initialized
    bool isOverlapped(const Square& other) const;

private:
    int x; //x-coord
    int y; //y-coord
    int f; //g+h
    int g; //number of moves to square
    int h; //distance of square to player
};

#endif