// Player.cpp
// This file contains the definitions for the Player class
// Created on Nov 10, 2026 by Jamie Listner

#include "Player.h"

// Constructor
Player::Player(int x, int y)
{
    x_loc = x;
    y_loc = y;
}

// Get functions
int Player::getX() const
{
    return x_loc;
}
int Player::getY() const
{
    return y_loc;
}

// Set functions
void Player::setX(int x)
{
    x_loc = x;
}
void Player::setY(int y)
{
    y_loc = y;
}