#include "threshold.hpp"

void Threshold::Apply(Image& img) {
    for(int i = 0; i < img.pixels.size(); ++i) {
        for (auto& pixel: img.pixels[i]) {
            auto new_color = 0.299 * pixel.red + 0.587 * pixel.green + 0.114 * pixel.blue;
            if (new_color > limit_) {
                new_color = 255;
            } else {
                new_color = 0;
            }
            pixel.red = new_color;
            pixel.blue = new_color;
            pixel.green = new_color;
        }
    }
}