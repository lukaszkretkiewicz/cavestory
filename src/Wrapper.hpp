#pragma once
#include "IWrapper.hpp"
class IPlayer;

class Wrapper : public IWrapper
{
public:
    Wrapper() : window(std::make_unique<sf::RenderWindow>(sf::VideoMode(512, 512), "CaveStroy", sf::Style::Default))
    {
        window->setFramerateLimit(60);
    };
    ~Wrapper() override {}

    bool isOpen() override { return window->isOpen(); }
    void close() override { window->close(); }
    bool pollEvent(sf::Event& evnt) override { return window->pollEvent(evnt); }

    void draw(std::unique_ptr<IPlayer>& player) override { window->draw(player->getShape()); }
    void display() override { window->display(); }
    void clear() override { window->clear(); }
    virtual sf::WindowBase& getWindow() override { return *window; }
    auto operator-> () { return window.get(); }

private:
    std::unique_ptr<sf::RenderWindow> window;
};