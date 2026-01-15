#include "negative.hpp"

void Negative::Apply(Image& img) {
    for (auto& pixel: img.pixels) {
        pixel.red = 255 - pixel.red;
        pixel.blue = 255 - pixel.blue;
        pixel.green = 255 - pixel.green;
    }
}