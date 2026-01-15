#pragma once

#include "../image/image.hpp"

class BaseFilter
{
public:
    virtual void Apply(Image& img) = 0;
};
