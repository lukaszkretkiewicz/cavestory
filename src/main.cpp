#include <SFML/Graphics.hpp>
#include "Game.hpp"
int main()
{
    Game game(std::make_unique<Wrapper>(),std::make_unique<Player>());
    game.start();

    return 0;
}