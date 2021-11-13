#pragma once
#include "IPlayer.hpp"
#include "IMovement.hpp"
class IWrapper;
class IMovement;

class Player : public IPlayer
{
public:
    Player(std::unique_ptr<IMovement> movemnt = std::make_unique<KeyboardMovement>())
        : shape(sf::Vector2f(100.0f, 100.0f)), movement(std::move(movemnt))
    {
    }
    ~Player() override = default;

    sf::RectangleShape getShape() override { return shape; }
    void move() override { movement->move(shape); }

private:
    sf::RectangleShape shape;
    std::unique_ptr<IMovement> movement;
};