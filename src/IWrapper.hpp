#pragma once
#include "SFML/Graphics.hpp"
class IWrapper
{
public:
    IWrapper() = default;
    virtual ~IWrapper() {}

    // virtual void createWindow(const char*) = 0;
    virtual bool isOpen() = 0;
    virtual void close() = 0;
    virtual bool pollEvent(sf::Event&) = 0;
};