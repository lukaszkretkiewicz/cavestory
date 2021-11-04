#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Game.hpp"
#include "WrapperMock.hpp"
#include "PlayerMock.hpp"
using namespace testing;

struct GameTest : public testing::Test
{
    std::unique_ptr<WrapperMock> wrapper;
    std::unique_ptr<PlayerMock> playerMock;
    void prepareLoop()
    {
        wrapper = std::make_unique<WrapperMock>();
        EXPECT_CALL(*wrapper, isOpen()).WillOnce(Return(true)).WillOnce(Return(false));
        EXPECT_CALL(*wrapper, close()).Times(1);
    }
    void prepareToDraw()
    {
        wrapper = std::make_unique<WrapperMock>();
        playerMock = std::make_unique<PlayerMock>();
        EXPECT_CALL(*wrapper, isOpen()).WillOnce(Return(true)).WillOnce(Return(false));
        EXPECT_CALL(*wrapper, pollEvent(_)).WillOnce(Return(false));
    }
    void expectUpdate()
    {
        EXPECT_CALL(*wrapper, clear());
        EXPECT_CALL(*wrapper, draw(NotNull()));
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

TEST_F(GameTest, canMovePlayer)
{
    prepareToDraw();
    expectUpdate();

    EXPECT_CALL(*playerMock, move()).Times(1);

    Game game(std::move(wrapper), std::move(playerMock));

    game.start();
}

// TEST_F(GameTest, canUseMouseToSetPlayerPosition)
// {
//     prepareToDraw();
//     expectUpdate();

//     EXPECT_CALL(*playerMock, setPosition(_));

//     Game game(std::move(wrapper), std::move(playerMock));

//     game.start();
// }