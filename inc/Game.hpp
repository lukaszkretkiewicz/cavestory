#include <memory>
#include "GraphicsBuilderAdapter.hpp"

template <class T>
class Game
{
public:
    Game(std::shared_ptr<T> _builder) : builder(_builder)
    {

        builder = std::make_shared<T>();
    };

    void gameLoop()
    {
        while (true)
        {
            if (SDL_PollEvent(&event))
                if (event.type == SDL_QUIT)
                    return;
        }
    }

private:
    std::shared_ptr<T> builder;
    SDL_Event event;
};