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
    std::shared_ptr<SDL_Window> window;
    std::shared_ptr<SDL_Renderer> renderer;

    MOCK_METHOD(int, CreateWindowAndRenderer, (int, int, uint32_t), (override));
    MOCK_METHOD(void, SetWindowTitle, (const char *), (override));
    MOCK_METHOD(int, DestroyWindow, (), (override));
    MOCK_METHOD(int, DestroyRenderer, (), (override));
    GraphicsBuilderMock() = default;
    ~GraphicsBuilderMock() = default;
};

TEST(GameTest, whenGameIsStartedPrepareWindow)
{
    std::shared_ptr<GraphicsBuilderMock> graphicsBuilderMock;
    EXPECT_CALL(*graphicsBuilderMock, CreateWindowAndRenderer(_, _, _)).WillRepeatedly(Return(0));
    EXPECT_CALL(*graphicsBuilderMock, SetWindowTitle(_));
    EXPECT_CALL(*graphicsBuilderMock, DestroyWindow()).WillRepeatedly(Return(1));
    EXPECT_CALL(*graphicsBuilderMock, DestroyRenderer()).WillRepeatedly(Return(1));
    Game<GraphicsBuilderMock> game(graphicsBuilderMock);
    //ASSERT_EQ(graphicsBuilderMock.window, 1);
}