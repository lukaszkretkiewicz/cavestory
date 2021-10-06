#pragma once
struct ISdlWrapper
{
    virtual SDL_Window *createWindow(const char *title, int x, int y, int w, int h, Uint32 flags) = 0;
    virtual void Init() = 0;
};