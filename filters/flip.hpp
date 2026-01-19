#pragma once

#include "base_filter.hpp"

class Flip : public BaseFilter
{
public:
    void Apply(Image& img) override;

};
