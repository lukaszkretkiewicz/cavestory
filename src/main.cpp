#include <SFML/Graphics.hpp>
#include "Game.hpp"
int main()
{
    Game game(std::make_unique<Wrapper>());
    sf::RectangleShape player(sf::Vector2f(100.0f,100.0f));
  
    game.start();



    return 0;
}