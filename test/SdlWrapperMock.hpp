#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "SDL2/SDL.h"
#include "ISdlWrapper.hpp"
#include "Graphics.hpp"

using namespace testing;

struct SdlWrapperMock : public ISdlWrapper
{
    MOCK_METHOD(void, Init, (), (override));
    MOCK_METHOD(SDL_Window *, createWindow, (const char *title, int x, int y, int w, int h, Uint32 flags), (override));
};

TEST(GameTest, whenGameIsStartedPrepareWindow)
{
    auto sdl = std::make_shared<SdlWrapperMock>();
    Graphics graphics(sdl);
}