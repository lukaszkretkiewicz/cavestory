#pragma once
#include "SFML/Graphics.hpp"
#include "Player.hpp"
class IWrapper
{
public:
    IWrapper() = default;
    virtual ~IWrapper() {}

    // virtual void createWindow(const char*) = 0;
    virtual bool isOpen() = 0;
    virtual void close() = 0;
    virtual bool pollEvent(sf::Event&) = 0;
    virtual void draw(Player) = 0;
    virtual void display() = 0;
};