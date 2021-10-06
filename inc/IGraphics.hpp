#pragma once
#include "SDL2/SDL.h"
#include <memory>
#include "ISdlWrapper.hpp"

struct IGraphics
{
    IGraphics();
    IGraphics(std::shared_ptr<ISdlWrapper>);
    virtual ~IGraphics();
};
