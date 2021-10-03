#include <memory>
#include "GraphicsBuilderAdapter.hpp"

template <class T>
class Game
{
public:
    Game(std::shared_ptr<T> _builder) : builder(_builder)
    {
        builder = std::make_shared<T>();
    }

protected:
    std::shared_ptr<T> builder;
};