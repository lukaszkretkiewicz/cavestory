#include "gmock/gmock.h"
#include "IWrapper.hpp"

class WrapperMock : public IWrapper
{
public:
    WrapperMock() = default;
    ~WrapperMock() override {}
    MOCK_METHOD(bool, isOpen, (), (override));
    MOCK_METHOD(void, close, (), (override));
    MOCK_METHOD(bool, pollEvent, (sf::Event&), (override));
};