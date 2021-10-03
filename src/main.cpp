#include "SDL.h"
#include "Game.hpp"
int main()
{
  std::shared_ptr<GraphicsBuilderAdapter> graphicsBuilder;
  // Game<GraphicsBuilderAdapter> game(std::make_shared<GraphicsBuilderAdapter>());
   Game<GraphicsBuilderAdapter> game(graphicsBuilder);
  return 0;
}