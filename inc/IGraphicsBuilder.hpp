#include "SDL2/SDL.h"
#pragma once
class IGraphicsBuilder
{
// public:
//     virtual void start() = 0;

protected:
    virtual int CreateWindowAndRenderer(int width, int height, uint32_t window_flags,
                                        SDL_Window *window, SDL_Renderer *renderer) = 0;
    virtual void SetWindowTitle(SDL_Window *window,
                                const char *title) = 0;
    virtual int DestroyWindow(SDL_Window *window) = 0;
    virtual int DestroyRenderer(SDL_Renderer *renderer) = 0;
};