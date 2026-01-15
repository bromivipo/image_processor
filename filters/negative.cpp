#include "negative.hpp"

void Negative::Apply(Image& img) {
    for(int i = 0; i < img.pixels.size(); ++i) {
        for (auto& pixel: img.pixels[i]) {
            pixel.red = 255 - pixel.red;
            pixel.blue = 255 - pixel.blue;
            pixel.green = 255 - pixel.green;
        }
    }
}