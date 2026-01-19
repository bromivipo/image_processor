#pragma once

#include "base_filter.hpp"

class Rotate : public BaseFilter
{
public:
    void Apply(Image& img) override;

};
