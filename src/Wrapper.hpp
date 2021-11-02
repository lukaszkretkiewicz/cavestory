#pragma once
#include "IWrapper.hpp"

class Wrapper : public IWrapper
{
public:
    Wrapper() : window(std::make_unique<sf::RenderWindow>(sf::VideoMode(512, 512), "CaveStroy", sf::Style::Default)){};
    ~Wrapper() override {}

    bool isOpen() override { return window->isOpen(); }
    void close() override { window->close(); }
    bool pollEvent(sf::Event& evnt) override { return window->pollEvent(evnt); }

    void draw(Player player) { window->draw(player.getShape()); }
    void display() { window->display(); }
    auto operator-> () { return window.get(); }

private:
    std::unique_ptr<sf::RenderWindow> window;
};