#include <SFML/Graphics.hpp>
#include "Game.hpp"
int main()
{
    //event loop
    //ecs

    //data driven
    //entt - tworzy rejestr, komponenty s dodawane do encji, w jaki sposob sa
    Game game(std::make_unique<Wrapper>(),std::make_unique<Player>());
    game.start();

    return 0;
}