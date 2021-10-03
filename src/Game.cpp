#include "Game.hpp"

// template <class T>
// Game<T>::Game(std::shared_ptr<T> _builder) : builder(_builder)
// {
//     SDL_Init(SDL_INIT_EVERYTHING);
//     builder = std::make_shared<T>();
// }
// template <class T>
// void Game<T>::gameLoop()
// {
//     while (true)
//     {
//         if (SDL_PollEvent(&event))
//             if (event.type == SDL_QUIT)
//                 return;
//     }
// }