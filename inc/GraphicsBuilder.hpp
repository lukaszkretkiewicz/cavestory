#include "IGraphicsBuilder.hpp"
#include <memory>
struct SDL_Window;
struct SDL_Renderer;

class GraphicsBuilder : public IGraphicsBuilder
{
    GraphicsBuilder()
    {
        CreateWindowAndRenderer(width, height, 0, this->window, this->renderer);
        SetWindowTitle(window, "Cavestory");
    }
    ~GraphicsBuilder()
    {
        DestroyWindow(window);
        DestroyRenderer(renderer);
    }

private:
    int width = 800;
    int height = 640;
    SDL_Window *window;
    SDL_Renderer *renderer;
    int CreateWindowAndRenderer(int _width, int _height, uint32_t window_flags,
                                SDL_Window *_window, SDL_Renderer *_renderer) override
    {
        SDL_CreateWindowAndRenderer(_width, _height, window_flags, &_window, &_renderer);
    }
    void SetWindowTitle(SDL_Window *_window,
                        const char *title) override
    {
        SDL_SetWindowTitle(_window, "Cavestory");
    }
    int DestroyWindow(SDL_Window *window) override
    {
        SDL_DestroyWindow(window);
    }
    int DestroyRenderer(SDL_Renderer *renderer) override
    {
        SDL_DestroyRenderer(renderer);
    }
};
