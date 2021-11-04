#pragma once
#include "IPlayer.hpp"
class IWrapper;

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

    void setPosition(const std::unique_ptr<IWrapper>& wrapper) override
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(wrapper->getWindow());
            shape.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        }
    }

private:
    unsigned int livesLeft = 0;
    sf::RectangleShape shape;
};