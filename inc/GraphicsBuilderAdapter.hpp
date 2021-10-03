#include "IGraphicsBuilder.hpp"
#include <memory>
struct SDL_Window;
struct SDL_Renderer;

class GraphicsBuilderAdapter : public IGraphicsBuilder
{
public:
    GraphicsBuilderAdapter()
    {
        CreateWindowAndRenderer(width, height, 0);
        SetWindowTitle();
    }
    ~GraphicsBuilderAdapter()
    {
        DestroyWindow();
        DestroyRenderer();
    }

private:
    int width = 800;
    int height = 640;
    SDL_Window *window;
    SDL_Renderer *renderer;

    void CreateWindowAndRenderer(int _width, int _height, Uint32 _window_flags) override
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_CreateWindowAndRenderer(_width, _height, _window_flags, &window, &renderer);
    }
    void SetWindowTitle(const char *title = "Cavestory") override
    {
        SDL_SetWindowTitle(window, title);
    }
    void DestroyWindow() override
    {
        SDL_DestroyWindow(window);
    }
    void DestroyRenderer() override
    {
        SDL_DestroyRenderer(renderer);
    }
};
