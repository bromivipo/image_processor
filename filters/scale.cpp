#include "scale.hpp"

void Scale::Apply(Image& img) {
    uint32_t new_width = uint32_t(img.dib_header.width / koef_);
    uint32_t new_height = uint32_t(img.dib_header.height / koef_);
    auto new_pixels = std::vector<std::vector<Image::Pixel>>(new_height, std::vector<Image::Pixel>(new_width));
    for (size_t row = 0; row < new_height; ++row) {
        for (size_t col = 0; col < new_width; ++col) {
            size_t old_col(col * koef_);
            size_t old_row(row * koef_);
            if (old_col >= img.dib_header.width || old_row >= img.dib_header.height) {
                continue;
            }
            new_pixels[row][col] = img.pixels[old_row][old_col];
        }
    }
    img.pixels = std::move(new_pixels);
    img.dib_header.bitmap_size = (new_width * 3 + (4 - new_width * 3 % 4) % 4) * new_height;
    img.dib_header.width = new_width;
    img.dib_header.height = new_height;
    img.bmp_header.file_size = img.dib_header.bitmap_size + img.bmp_header.offset;
}