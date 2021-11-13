#include "IPlayer.hpp"
#include "gmock/gmock.h"

class PlayerMock : public IPlayer
{
public:
    PlayerMock() = default;
    ~PlayerMock() override = default;
    MOCK_METHOD(sf::RectangleShape, getShape, (), (override));
    MOCK_METHOD(void, move, (), (override));
};