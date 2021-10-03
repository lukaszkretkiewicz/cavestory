#include "IGraphicsBuilder.hpp"
#include <memory>
struct SDL_Window;
struct SDL_Renderer;

class GraphicsBuilderAdapter : public IGraphicsBuilder
{
public:
    GraphicsBuilderAdapter()
    {
        window=std::make_shared<SDL_Window*>();
        renderer=std::make_shared<SDL_Renderer*>();
        CreateWindowAndRenderer(width, height, 0);
        SetWindowTitle("Cavestory");
    }
    ~GraphicsBuilderAdapter()
    {
        DestroyWindow();
        DestroyRenderer();
    }

private:
    int width = 800;
    int height = 640;
    std::shared_ptr<SDL_Window* > window;
    std::shared_ptr<SDL_Renderer *> renderer;

    int CreateWindowAndRenderer(int _width, int _height, uint32_t _window_flags) override
    {
        SDL_CreateWindowAndRenderer(_width, _height, _window_flags, window.get(), renderer.get());
    }
    void SetWindowTitle(const char *title="Cavestory") override
    {
        SDL_SetWindowTitle(*window, title);
    }
    int DestroyWindow() override
    {
        SDL_DestroyWindow(*window);
    }
    int DestroyRenderer() override
    {
        SDL_DestroyRenderer(*renderer);
    }
};
