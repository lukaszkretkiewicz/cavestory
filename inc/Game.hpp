#include <memory>
#include "GraphicsBuilder.hpp"
#include "IGame.hpp"
class Game : public IGame
{
public:
    Game(std::shared_ptr<IGraphicsBuilder> _builder) : builder(_builder)
    {
        // std::make_shared<GraphicsBuilder>(builder);
    }

protected:
    std::shared_ptr<IGraphicsBuilder> builder;
};