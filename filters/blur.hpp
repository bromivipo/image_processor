#pragma once

#include "base_filter.hpp"

class Blur : public BaseFilter
{
public:
    void Apply(Image& img) override;
};
