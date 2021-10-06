#include "SDL2/SDL.h"
#include "Graphics.hpp"
int main()
{
  //std::shared_ptr<Graphics> graphics;
  //Game<Graphics> game(graphics);
  //game.gameLoop();
  Graphics graphics;
//  auto wrapper = std::make_shared<SdlWrapper>();
  Graphics graphicsWrapper(std::make_shared<SdlWrapper>());
  return 0;
}
