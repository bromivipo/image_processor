#pragma once

#include "base_filter.hpp"

class Threshold : public BaseFilter
{
private:
    uint8_t limit_;
public:
    Threshold(uint8_t limit) : limit_(limit) {};
    void Apply(Image& img) override;
};
