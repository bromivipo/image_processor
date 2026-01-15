#include "blur.hpp"

void Blur::Apply(Image& img) {
    std::vector<Image::Pixel> new_pixels = img.pixels;
    for (size_t i = 0; i < img.pixels.size(); ++i) {
        size_t cur_row = i / img.dib_header.width;
        size_t cur_col = i % img.dib_header.width;
        int count = 0;
        uint16_t result_r = 0;
        uint16_t result_g = 0;
        uint16_t result_b = 0;
        // top left
        if (cur_col != 0 && cur_row != 0) {
            
        }
    }
}