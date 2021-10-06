#include "gtest/gtest.h"
#include "SdlWrapperMock.hpp"
#define SDL_MAIN_HANDLED
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}