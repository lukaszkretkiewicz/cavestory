#include "ISdlWrapper.hpp"
struct SdlWrapper : public ISdlWrapper
{
    SDL_Window *createWindow(const char *title, int x, int y, int w, int h, Uint32 flags) override
    {
        return SDL_CreateWindow(title, x, y, w, h, flags);
    }
    void Init() override
    {
        SDL_Init(SDL_INIT_EVERYTHING);
    }
};