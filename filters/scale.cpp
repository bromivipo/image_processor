#include "scale.hpp"

void Scale::Apply(Image& img) {
    uint32_t new_width = uint32_t(img.dib_header.width / koef_);
    uint32_t new_height = uint32_t(img.dib_header.height / koef_);
    std::vector<Image::Pixel> new_pixels;
    new_pixels.reserve(new_height * new_width);
    for (size_t row = 0; row < new_height; ++row) {
        for (size_t i = 0; i < new_width; ++i) {
            size_t old_x(i * koef_);
            size_t old_y(row * koef_);
            if (old_x >= img.dib_header.width || old_y >= img.dib_header.height) {
                continue;
            }
            new_pixels.push_back(img.pixels[old_y * img.dib_header.width + old_x]);
        }
    }
    img.pixels = std::move(new_pixels);
    img.dib_header.bitmap_size = (new_width * 3 + (4 - new_width * 3 % 4) % 4) * new_height;
    img.dib_header.width = new_width;
    img.dib_header.height = new_height;
    img.bmp_header.file_size = img.dib_header.bitmap_size + img.bmp_header.offset;
}