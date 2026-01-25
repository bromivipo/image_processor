#pragma once

#include "base_filter.hpp"

class Flip : public BaseFilter
{
private:
    bool is_horizontal;
public:
    Flip(char c) : is_horizontal(c=='h') {};
    void Apply(Image& img) override;

};
