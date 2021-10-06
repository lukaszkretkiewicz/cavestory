#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "SDL2/SDL.h"

#include "Graphics.hpp"
//#include "Game.hpp"

//struct SDL_Deleter; 

using namespace testing;

class SdlWrapperMock : public ISdlWrapper
{
public:
    int screen_width = 800;
    int screen_height = 640;

    MOCK_METHOD(SDL_Window*, CreateWindow, (const char *title, int x, int y, int w, int h, Uint32 flags), (override));
    MOCK_METHOD(int, Init, (), (override));
    SdlWrapperMock () = default;
    ~SdlWrapperMock () = default;
};

TEST(GameTest, whenGameIsStartedPrepareWindow)
{
    auto sdl = std::make_shared<SdlWrapperMock>();
    Graphics graphics(sdl);
    EXPECT_CALL(*sdl, CreateWindow(_, _, _, _ ,_, _)).Times(1);
    EXPECT_CALL(*sdl, Init()).Times(1);
//    Game<GraphicsBuilderMock> game(graphicsBuilderMock);
    // ASSERT_EQ(graphicsBuilderMock.window, 1);
}
