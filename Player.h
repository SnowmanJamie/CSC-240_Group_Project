// Player.h
// This file contains the definition for the user-controlled Player class
// Created on Nov 10, 2026 by Jamie Listner



#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    // Constructor
    // Post: Player is initialized with x_loc and y_loc set to x and y
    Player(int x, int y);
private:
    int x_loc;
    int y_loc;
};


#endif