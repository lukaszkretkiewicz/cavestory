#pragma once
#include "Wrapper.hpp"

class Player
{
public:
    Player() : shape(sf::Vector2f(100.0f, 100.0f)) {}
    ~Player() = default;

    auto getShape(){return shape;}

private:
    unsigned int livesLeft = 0;
    sf::RectangleShape shape;
};