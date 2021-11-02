#include <SFML/Graphics.hpp>
#include "Game.hpp"
int main()
{
    Game game(std::make_unique<Wrapper>());
    game.start();

    // sf::RenderWindow window(sf::VideoMode(512, 512), "Cavestory", sf::Style::Default);

    // while (window.isOpen())
    // {
    //     sf::Event evnt;
    //     while (window.pollEvent(evnt))
    //     {
    //         switch (evnt.type)
    //         {
    //             case sf::Event::Closed:
    //                 window.close();
    //                 break;
    //             case sf::Event::Resized:
    //                 std::cout << "New window width: " << evnt.size.width
    //                           << "New window height: " << evnt.size.height << std::endl;
    //                 break;
    //             case sf::Event::TextEntered:
    //                 if (evnt.text.unicode < 128)
    //                     std::cout << evnt.text.unicode;
    //                 break;
    //             default:
    //                 continue;
    //         }
    //     }
    // }

    return 0;
}