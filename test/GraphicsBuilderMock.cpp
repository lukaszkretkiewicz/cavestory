#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "IGraphicsBuilder.hpp"
#include "SDL2/SDL.h"
// SDL_Window *SDL_Window_ptr;
// SDL_Renderer *SDL_Renderer_ptr;
class GraphicsBuilderMock : public IGraphicsBuilder
{
private:
    int screen_width = 800;
    int screen_height = 640;
    std::unique_ptr<SDL_Window> SDL_Window_ptr;
    std::unique_ptr<SDL_Renderer> SDL_Renderer_ptr;

public:
    MOCK_METHOD(int, SDL_CreateWindowAndRenderer, (int, int, uint32_t, decltype(SDL_Window_ptr.get()), decltype(SDL_Renderer_ptr.get())), ());
    MOCK_METHOD(int, SDL_SetWindowTitle, (decltype(SDL_Window_ptr.get()), const char *), ());
    MOCK_METHOD(int, SDL_DestroyWindow, (decltype(SDL_Window_ptr.get())), ());
    MOCK_METHOD(int, SDL_DestroyRenderer, (decltype(SDL_Window_ptr.get())), ());

    void SetUp()
    {
        SDL_CreateWindowAndRenderer(screen_width, screen_height, 0, SDL_Window_ptr.get(), SDL_Renderer_ptr.get());
        SDL_SetWindowTitle(SDL_Window_ptr.get(), "Cavestory");
    }
};
// TEST_F(GraphicsBuilderMock, whenGameIsStartedPrepareWindow)
// {
    
// }