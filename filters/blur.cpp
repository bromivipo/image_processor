#include "blur.hpp"

void Blur::Apply(Image& img) {
    auto new_pixels = img.pixels;
    for (int row = 0; row < img.pixels.size(); ++row) {
        for (int col = 0; col < img.pixels[row].size(); ++col) {
            int count = 0;
            RGBSum sum;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (0 <= col + dx && col + dx < img.dib_header.width && 0 <= row + dy && row + dy < img.dib_header.height) {
                        sum += img.pixels[row + dy][col + dx];
                        ++count;
                    }
                }
            }
            new_pixels[row][col] = {.blue = uint8_t(sum.blue / count), .green = uint8_t(sum.green / count), .red = uint8_t(sum.red / count)};
        }
    }
    img.pixels = std::move(new_pixels);
}