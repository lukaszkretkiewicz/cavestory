#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Game.hpp"
#include "Wrapper.hpp"
#include "WrapperMock.hpp"
using namespace testing;

// TEST(WrapperTest, whenWrapperIsCreatedShouldPrepareWindow)
// {
//     Wrapper();
// }

// TEST(GameTest, whenGameIsCreatedShouldPrepareWindow)
// {
//     WrapperMock wrapper;
//     // EXPECT_CALL(wrapper, createWindow("CaveStory")).Times(1);

//     Game game(wrapper);
// }

// TEST(GameTest, whenGameIsStartedShouldPrepareLoopThenEventBreakIt)
// {
//     WrapperMock wrapper;
//     EXPECT_CALL(wrapper, isWindowOpen()).WillRepeatedly(Return(true));
//     EXPECT_CALL(wrapper, closeWindow()).Times(1);
//     Game game(wrapper);
//     // game.receiveEvent(sf::Event::Closed);
//     game.start();
// }
