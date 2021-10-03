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

<<<<<<< HEAD
    MOCK_METHOD(int, CreateWindowAndRenderer, (int, int, uint32_t), (override));
    MOCK_METHOD(void, SetWindowTitle, (const char *), (override));
    MOCK_METHOD(int, DestroyWindow, (), (override));
    MOCK_METHOD(int, DestroyRenderer, (), (override));
=======
    MOCK_METHOD(void, CreateWindowAndRenderer, (int, int, Uint32), (override));
    MOCK_METHOD(void, SetWindowTitle, (const char *), (override));
    MOCK_METHOD(void, DestroyWindow, (), (override));
    MOCK_METHOD(void, DestroyRenderer, (), (override));
>>>>>>> Draft
    GraphicsBuilderMock() = default;
    ~GraphicsBuilderMock() = default;
};

TEST(GameTest, whenGameIsStartedPrepareWindow)
{
    std::shared_ptr<GraphicsBuilderMock> graphicsBuilderMock;
<<<<<<< HEAD
    EXPECT_CALL(*graphicsBuilderMock, CreateWindowAndRenderer(_, _, _)).WillRepeatedly(Return(0));
    EXPECT_CALL(*graphicsBuilderMock, SetWindowTitle(_));
    EXPECT_CALL(*graphicsBuilderMock, DestroyWindow()).WillRepeatedly(Return(1));
    EXPECT_CALL(*graphicsBuilderMock, DestroyRenderer()).WillRepeatedly(Return(1));
    Game<GraphicsBuilderMock> game(graphicsBuilderMock);
    //ASSERT_EQ(graphicsBuilderMock.window, 1);
=======
    EXPECT_CALL(*graphicsBuilderMock, CreateWindowAndRenderer(_, _, _)).Times(1);
    EXPECT_CALL(*graphicsBuilderMock, SetWindowTitle(_)).Times(1);
    EXPECT_CALL(*graphicsBuilderMock, DestroyWindow()).Times(1);
    EXPECT_CALL(*graphicsBuilderMock, DestroyRenderer()).Times(1);
    Game<GraphicsBuilderMock> game(graphicsBuilderMock);
    // ASSERT_EQ(graphicsBuilderMock.window, 1);
>>>>>>> Draft
}