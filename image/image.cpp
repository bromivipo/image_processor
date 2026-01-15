#include "image.hpp"
#include <fstream>

void Image::LoadImage(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    file.read(reinterpret_cast<char*>(&bmp_header), sizeof(BmpHeader));
    file.read(reinterpret_cast<char*>(&dib_header), sizeof(DibHeader));
    pixels.reserve(dib_header.width * dib_header.height);
    for (size_t row = 0; row < dib_header.height; ++row) {
        for (size_t i = 0; i < dib_header.width; ++i) {
            Pixel px;
            file.read(reinterpret_cast<char*>(&px), sizeof(Pixel));
            pixels.push_back(px);
        }
        file.seekg((4 - dib_header.width * 3 % 4) % 4, std::ios::cur);
    }
}

void Image::SaveImage(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    file.write(reinterpret_cast<char*>(&bmp_header), sizeof(BmpHeader));
    file.write(reinterpret_cast<char*>(&dib_header), sizeof(DibHeader));
    for (size_t row = 0; row < dib_header.height; ++row) {
        for (size_t i = 0; i < dib_header.width; ++i) {
            file.write(reinterpret_cast<char*>(&pixels[row * dib_header.width + i]), sizeof(Pixel));
        }
        for (int j = 0; j < (4 - dib_header.width * 3 % 4) % 4; ++j) {
            file.put(0);
        }
    }
}

Image::Image(const std::string& filename) {
    LoadImage(filename);
}