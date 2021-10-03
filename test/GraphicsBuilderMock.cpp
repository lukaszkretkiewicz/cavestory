#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "IGraphicsBuilder.hpp"
#include "SDL2/SDL.h"
#include "Game.hpp"

using namespace testing;

class GraphicsBuilderMock : public IGraphicsBuilder
{
public:
    int screen_width = 800;
    int screen_height = 640;
    std::unique_ptr<SDL_Window> window;
    std::unique_ptr<SDL_Renderer> renderer;

    MOCK_METHOD(int, CreateWindowAndRenderer, (int, int, uint32_t, decltype(window.get()), decltype(renderer.get())), (override));
    MOCK_METHOD(void, SetWindowTitle, (decltype(window.get()), const char *), (override));
    MOCK_METHOD(int, DestroyWindow, (decltype(window.get())), (override));
    MOCK_METHOD(int, DestroyRenderer, (decltype(renderer.get())), (override));
    GraphicsBuilderMock() = default;
    ~GraphicsBuilderMock() = default;
};

TEST(GameTest, whenGameIsStartedPrepareWindow)
{
    std::shared_ptr<GraphicsBuilderMock> graphicsBuilderMock;
    EXPECT_CALL(*graphicsBuilderMock, CreateWindowAndRenderer(_, _, _, _, _)).WillRepeatedly(Return(0));
    EXPECT_CALL(*graphicsBuilderMock, SetWindowTitle(_, _));
    EXPECT_CALL(*graphicsBuilderMock, DestroyWindow(_)).WillRepeatedly(Return(1));
    EXPECT_CALL(*graphicsBuilderMock, DestroyRenderer(_)).WillRepeatedly(Return(1));
    Game game(graphicsBuilderMock);
    // ASSERT_EQ(graphicsBuilderMock.window, 1);
}