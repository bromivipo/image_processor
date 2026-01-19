#pragma once

#include "base_filter.hpp"

class Scale : public BaseFilter
{
public:
    Scale(double koef) : koef_(koef) {};

    void Apply(Image& img) override;

    double koef_;
};
