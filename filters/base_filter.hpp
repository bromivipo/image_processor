#pragma once

#include "../image/image.hpp"

class BaseFilter {

protected:
    struct RGBSum {
        RGBSum& operator+=(const Image::Pixel& px);
        RGBSum& operator-=(const Image::Pixel& px);

        uint16_t blue = 0;
        uint16_t green = 0;
        uint16_t red = 0;
    };
public:
    virtual void Apply(Image& img) = 0;
};
