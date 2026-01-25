#include "rotate.hpp"

void Rotate::Apply(Image& img) {
    auto new_pixels = std::vector<std::vector<Image::Pixel>>(img.dib_header.width, std::vector<Image::Pixel>(img.dib_header.height));
    for (int row = 0; row < img.pixels.size(); ++row) {
        for (int col = 0; col < img.pixels[row].size(); ++col) {
            new_pixels[col][img.pixels.size() - 1 - row] = img.pixels[row][col];
        }
    }
    img.pixels = std::move(new_pixels);
}