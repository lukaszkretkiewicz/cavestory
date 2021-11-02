#include <SFML/Graphics.hpp>
#include "Game.hpp"
int main()
{
    Game game(std::make_unique<Wrapper>());
    game.start();



    return 0;
}