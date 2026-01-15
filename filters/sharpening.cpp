#include "sharpening.hpp"

void Sharpening::Apply(Image& img) {
    auto new_pixels = img.pixels;
    for (int row = 0; row < img.pixels.size(); ++row) {
        for (int col = 0; col < img.pixels[row].size(); ++col) {
            RGBSum sum = {
                .blue = uint16_t(5 * int(img.pixels[row][col].blue)),
                .green = uint16_t(5 * int(img.pixels[row][col].green)),
                .red = uint16_t(5 * int(img.pixels[row][col].red))
            };
            for (int dx = -1; dx <= 1; dx += 2) {
                if (0 <= col + dx && col + dx < img.dib_header.width) {
                    sum -= img.pixels[row][col + dx];
                } else {
                    sum -= img.pixels[row][col];
                }
                if (0 <= row + dx && row + dx < img.dib_header.height) {
                    sum -= img.pixels[row + dx][col];
                } else {
                    sum -= img.pixels[row][col];
                }
            }
            new_pixels[row][col] = {
                .blue = uint8_t(std::min(sum.blue, uint16_t(255))), 
                .green = uint8_t(std::min(sum.green, uint16_t(255))),
                .red = uint8_t(std::min(sum.red, uint16_t(255)))
            };
        }
    }
    img.pixels = std::move(new_pixels);
}