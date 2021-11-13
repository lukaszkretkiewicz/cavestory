#pragma once
#include "IWrapper.hpp"

class IPlayer
{
public:
    virtual ~IPlayer() {}
    virtual sf::RectangleShape getShape() = 0;
    virtual void move() = 0;
};