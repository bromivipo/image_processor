#include "base_filter.hpp"

BaseFilter::RGBSum& BaseFilter::RGBSum::operator+=(const Image::Pixel& px) {
    blue += px.blue;
    green += px.green;
    red += px.red;
    return *this;
}

BaseFilter::RGBSum& BaseFilter::RGBSum::operator-=(const Image::Pixel& px) {
    if (blue < px.blue) {
        blue = 0;
    } else {
        blue -= px.blue;
    }
    if (green < px.green) {
        green = 0;
    } else {
        green -= px.green;
    }
    if (red < px.red) {
        red = 0;
    } else {
        red -= px.red;
    }
    return *this;
}