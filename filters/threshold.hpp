#pragma once

#include "base_filter.hpp"

class Threshold : public BaseFilter
{
public:
    void Apply(Image& img) override;
};
