#pragma once

#include "base_filter.hpp"

class Negative : public BaseFilter
{
public:
    void Apply(Image& img) override;
};
