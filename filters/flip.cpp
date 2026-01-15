#include "flip.hpp"

void Flip::Apply(Image& img) {
    for (int row = 0; row < img.pixels.size(); ++row) {
        for (int col = 0; col < img.pixels[row].size() / 2; ++col) {
            std::swap(img.pixels[row][col], img.pixels[row][img.pixels[row].size() - 1 - col]);
        }
    }
}