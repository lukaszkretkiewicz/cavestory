#pragma once
#include "IGraphics.hpp"

class Graphics : public IGraphics
{
public:
    Graphics() {}
    ~Graphics() override {}

private:
    int width = 800;
    int height = 640;
};