#include "SDL2/SDL.h"
#include "Game.hpp"
int main()
{
  std::shared_ptr<GraphicsBuilderAdapter> graphicsBuilder;
  Game<GraphicsBuilderAdapter> game(graphicsBuilder);
  game.gameLoop();
  return 0;
}