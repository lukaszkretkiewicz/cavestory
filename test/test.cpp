#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Game.hpp"
#include "Wrapper.hpp"
#include "WrapperMock.hpp"
using namespace testing;

struct GameTest : public testing::Test
{
    std::unique_ptr<WrapperMock> wrapper;
    void prepareLoop()
    {
        wrapper = std::make_unique<WrapperMock>();
        EXPECT_CALL(*wrapper, isOpen()).WillOnce(Return(true)).WillOnce(Return(false));
        EXPECT_CALL(*wrapper, close()).Times(1);
    }
    void prepareToDraw()
    {
        wrapper = std::make_unique<WrapperMock>();
        EXPECT_CALL(*wrapper, isOpen()).WillOnce(Return(true)).WillOnce(Return(false));
        EXPECT_CALL(*wrapper, pollEvent(_)).WillOnce(Return(false));
    }
    void expectUpdate()
    {
        EXPECT_CALL(*wrapper, clear());
        EXPECT_CALL(*wrapper, draw(_));
        EXPECT_CALL(*wrapper, display());
    }
};

TEST_F(GameTest, whenGameIsStartedShouldPrepareLoopThenEventBreakIt)
{
    prepareLoop();

    Game game(std::move(wrapper));
    sf::Event evnt;
    evnt.type = sf::Event::Closed;
    game.receiveExternalEvent(evnt);
    game.start();
}

TEST_F(GameTest, canDrawPlayer)
{
    prepareToDraw();
    expectUpdate();
    Game game(std::move(wrapper));

    game.start();
}

// TEST_F(GameTest, canMovePlayer)
// {
//     prepareToDraw();
//     expectUpdate();
//     Game game(std::move(wrapper));

//     game.start();
// }