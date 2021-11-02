#include "Wrapper.hpp"
#include <iostream>
class Game
{
public:
    Game() = delete;
    Game(std::unique_ptr<IWrapper> _wrapper) : wrapper(std::move(_wrapper)) {}
    void start()
    {
        while (isWindowOpen())
        {
            executeEvent();
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
    bool isExternalEventReceived = false;

    bool isWindowOpen(){ return wrapper->isOpen();}

    void executeEvent()
    {
        while (isEventReceived())
        {
            switch (actualEvent.type)
            {
                case sf::Event::Closed:
                    wrapper->close();
                    break;
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
};