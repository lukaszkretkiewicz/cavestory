#include "SDL2/SDL.h"
#pragma once
class IGraphics
{
protected:
    virtual void CreateWindowAndRenderer(int width, int height, Uint32 window_flags) = 0;
    virtual void SetWindowTitle(const char *title) = 0;
//    virtual void DestroyWindow() = 0;
//    virtual void DestroyRenderer() = 0;
};
