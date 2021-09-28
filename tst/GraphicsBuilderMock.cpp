#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "IGraphicsBuilder.hpp"
#include "SDL2/SDL.h"

class GraphicsBuilderMock : public IGraphicsBuilder
{
public:
    //MOCK_METHOD(int, SDL_CreateWindowAndRenderer, (int, int, uint32_t, SDL_Window, SDL_Renderer),());
};