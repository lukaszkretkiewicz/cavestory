#pragma once

#include "SDL2/SDL.h"
#include <memory>
struct SDL_Window;
struct SDL_Renderer;

//namespace Cave ??
//
struct SDL_Deleter {
  void operator()(SDL_Surface*  ptr) { if (ptr) SDL_FreeSurface(ptr); }
  void operator()(SDL_Texture*  ptr) { if (ptr) SDL_DestroyTexture(ptr); }
  void operator()(SDL_Renderer* ptr) { if (ptr) SDL_DestroyRenderer(ptr); }
  void operator()(SDL_Window*   ptr) { if (ptr) SDL_DestroyWindow(ptr); }
  void operator()(SDL_RWops*    ptr) { if (ptr) SDL_RWclose(ptr); }
};

//struct SDL_Deleter
//{
//  void operator()(SDL_Window *p) const { SDL_DestroyWindow(p); }
//  void operator()(SDL_Renderer *p) const { SDL_DestroyRenderer(p); }
//  void operator()(SDL_Texture *p) const { SDL_DestroyTexture(p); }
//};
//
//std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window_;
//
struct ISdlWrapper
{
    virtual SDL_Window* CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags) = 0;
    virtual int Init() = 0;
};


//namespace SDL_Wrapper
struct SdlWrapper : ISdlWrapper
{

SDL_Window* CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags)  override
    {
    return SDL_CreateWindow(title, x, y, w, h, flags);
    }

    int Init() override
    {
    return SDL_Init(SDL_INIT_EVERYTHING);
    }
};

 
using SurfacePtr  = std::unique_ptr<SDL_Surface,  SDL_Deleter>;
using TexturePtr  = std::unique_ptr<SDL_Texture,  SDL_Deleter>;
using RendererPtr = std::unique_ptr<SDL_Renderer, SDL_Deleter>;
using WindowPtr   = std::unique_ptr<SDL_Window,   SDL_Deleter>;
using RWopsPtr    = std::unique_ptr<SDL_RWops,    SDL_Deleter>;


//class Graphics : public IGraphics
class Graphics
{
public:
    Graphics() : window(nullptr, SDL_Deleter()), renderer(nullptr, SDL_Deleter())
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        window.reset(SDL_CreateWindow("Cavestory", 
                SDL_WINDOWPOS_UNDEFINED, 
                SDL_WINDOWPOS_UNDEFINED, 
                width, 
                height, 
                SDL_WINDOW_RESIZABLE));

        renderer.reset(SDL_CreateRenderer(window.get(), -1, 0));
    }


    Graphics(std::shared_ptr<ISdlWrapper> wrapper) : window(nullptr, SDL_Deleter()), renderer(nullptr, SDL_Deleter())
    {
        wrapper->Init();
        window.reset(wrapper->CreateWindow("Cavestory", 
                SDL_WINDOWPOS_UNDEFINED, 
                SDL_WINDOWPOS_UNDEFINED, 
                width, 
                height, 
                SDL_WINDOW_RESIZABLE));

        renderer.reset(SDL_CreateRenderer(window.get(), -1, 0));
   


    }

private:
    int width = 800; //int?
    int height = 640;
    WindowPtr window;
    RendererPtr renderer;

};
