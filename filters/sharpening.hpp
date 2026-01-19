#pragma once

#include "base_filter.hpp"

class Sharpening : public BaseFilter
{
public:
    void Apply(Image& img) override;
};
