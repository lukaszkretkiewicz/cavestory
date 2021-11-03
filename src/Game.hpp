#include "Wrapper.hpp"
#include "Player.hpp"
#include <iostream>
class Game
{
public:
    Game() = delete;
    ~Game() = default;
    Game(std::unique_ptr<IWrapper> _wrapper) : wrapper(std::move(_wrapper)), player(std::make_unique<Player>()) {} // to test without PlayerMock
    Game(std::unique_ptr<IWrapper> _wrapper, std::unique_ptr<IPlayer> _player) // to test with PlayerMock
        : wrapper(std::move(_wrapper)), player(std::move(_player))
    {
    }
    void start()
    {
        while (isWindowOpen())
            if (!isGoingToCloseAfterReceivingEvent())
            {
                player->move();
                updateWindow();
            }
    }
    void receiveExternalEvent(sf::Event evnt)
    {
        actualEvent = evnt;
        isExternalEventReceived = true;
    }

private:
    std::unique_ptr<IWrapper> wrapper;
    sf::Event actualEvent;
    std::unique_ptr<IPlayer> player;
    bool isExternalEventReceived = false;

    bool isWindowOpen() { return wrapper->isOpen(); }

    bool isGoingToCloseAfterReceivingEvent()
    {
        while (isEventReceived())
        {
            switch (actualEvent.type)
            {
                case sf::Event::Closed:
                    wrapper->close();
                    return true;
                case sf::Event::Resized:
                    std::cout << "New window width: " << actualEvent.size.width
                              << "New window height: " << actualEvent.size.height << std::endl;
                    break;
                case sf::Event::TextEntered:
                    if (actualEvent.text.unicode < 128)
                        std::cout << actualEvent.text.unicode;
                    break;
                default:
                    continue;
            }
        }
        return false;
    }

    bool isEventReceived()
    {
        if (isExternalEventReceived)
        {
            isExternalEventReceived = false;
            return true;
        }
        return wrapper->pollEvent(actualEvent);
    }
    void updateWindow()
    {
        wrapper->clear();
        wrapper->draw(dynamic_cast<Player&>(*player));
        wrapper->display();
    }
};