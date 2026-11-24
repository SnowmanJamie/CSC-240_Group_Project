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
    void setX(const int x);
    // Func: Returns y
    int getY() const;
    void setY(const int y);

    // Func: Returns if this and other share the same x and y values
    // Pre:  Both this and other anre initialized
    bool operator==(const Square& other) const;

private:
    int x; //x-coord
    int y; //y-coord
};

#endif