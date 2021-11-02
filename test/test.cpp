#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Game.hpp"
#include "Wrapper.hpp"
#include "WrapperMock.hpp"
using namespace testing;

TEST(WrapperTest, whenWrapperIsCreatedShouldPrepareWindow)
{
    Wrapper();
}

TEST(GameTest, whenGameIsCreatedShouldPrepareWindow)
{
    // EXPECT_CALL(wrapper, createWindow("CaveStory")).Times(1);

    Game game(std::make_unique<WrapperMock>());
}

TEST(GameTest, whenGameIsStartedShouldPrepareLoopThenEventBreakIt)
{
    auto wrapper=std::make_unique<WrapperMock>();
    EXPECT_CALL(*wrapper, isOpen()).WillOnce(Return(true)).WillOnce(Return(false));
    EXPECT_CALL(*wrapper, pollEvent(_)).WillOnce(Return(false));
    EXPECT_CALL(*wrapper, close()).Times(1);

    Game game(std::move(wrapper));
    sf::Event evnt;
    evnt.type=sf::Event::Closed;
    game.receiveExternalEvent(evnt);
    game.start();
}
