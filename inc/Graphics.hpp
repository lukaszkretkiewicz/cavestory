#include "IGraphics.hpp"
#include "SdlWrapper.hpp"
#include <memory>
#include "SDL2/SDL.h"
struct SDL_Window;
struct SDL_Renderer;

struct Sdl_Deleter
{
    void operator()(SDL_Surface* ptr) { if (ptr) SDL_FreeSurface(ptr); }
    void operator()(SDL_Texture* ptr) { if (ptr) SDL_DestroyTexture(ptr); }
    void operator()(SDL_Renderer* ptr) { if (ptr) SDL_DestroyRenderer(ptr); }
    void operator()(SDL_Window* ptr) { if (ptr) SDL_DestroyWindow(ptr); }
    void operator()(SDL_RWops* ptr) { if (ptr) SDL_RWclose(ptr); }
};

struct Graphics //: public IGraphics
{
    ~Graphics() = default;
    // Graphics() : window(nullptr, Sdl_Deleter())
    // {

    // };
    Graphics(std::shared_ptr<ISdlWrapper> wrapper) : window(nullptr, Sdl_Deleter())
    {
        wrapper->Init();
        window.reset(wrapper->createWindow(
            "CaveStory",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width,
            height,
            SDL_WINDOW_RESIZABLE));
    }

private:

    std::unique_ptr<SDL_Window, Sdl_Deleter> window;
    int width = 800;
    int height = 640;
};