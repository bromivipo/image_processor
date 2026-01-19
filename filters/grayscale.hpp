#pragma once

#include "base_filter.hpp"

class Grayscale : public BaseFilter
{
public:
    void Apply(Image& img) override;
};
