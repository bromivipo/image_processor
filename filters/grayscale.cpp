#include "grayscale.hpp"

void Grayscale::Apply(Image& img) {
    for (auto& pixel: img.pixels) {
        auto new_color = 0.299 * pixel.red + 0.587 * pixel.green + 0.114 * pixel.blue;
        pixel.red = new_color;
        pixel.blue = new_color;
        pixel.green = new_color;
    }
}