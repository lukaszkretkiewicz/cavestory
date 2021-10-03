#include "SDL2/SDL.h"
#pragma once
class IGraphicsBuilder
{
protected:
    virtual int CreateWindowAndRenderer(int width, int height, uint32_t window_flags) = 0;
    virtual void SetWindowTitle(const char *title) = 0;
    virtual int DestroyWindow() = 0;
    virtual int DestroyRenderer() = 0;
};