#pragma once
#include "Wrapper.hpp"
#include "IPlayer.hpp"
class Player : public IPlayer
{
public:
    Player() : shape(sf::Vector2f(100.0f, 100.0f)) {}
    ~Player() = default;

    sf::RectangleShape getShape() override { return shape; }
    void move() override
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            shape.move(-0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            shape.move(0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            shape.move(0.0f, -0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            shape.move(0.0f, 0.1f);
        }
    }

private:
    unsigned int livesLeft = 0;
    sf::RectangleShape shape;
};