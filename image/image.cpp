#include "image.hpp"
#include <fstream>


void Image::LoadImage(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    file.read(reinterpret_cast<char*>(&bmp_header), sizeof(BmpHeader));
    file.read(reinterpret_cast<char*>(&dib_header), sizeof(DibHeader));
    pixels = std::vector<std::vector<Image::Pixel>>(dib_header.height, std::vector<Image::Pixel>(dib_header.width));
    for (size_t row = 0; row < dib_header.height; ++row) {
        for (size_t col = 0; col < dib_header.width; ++col) {
            Pixel px;
            file.read(reinterpret_cast<char*>(&px), sizeof(Pixel));
            pixels[row][col] = px;
        }
        file.seekg((4 - dib_header.width * 3 % 4) % 4, std::ios::cur);
    }
}

void Image::SaveImage(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    file.write(reinterpret_cast<char*>(&bmp_header), sizeof(BmpHeader));
    file.write(reinterpret_cast<char*>(&dib_header), sizeof(DibHeader));
    for (size_t row = 0; row < dib_header.height; ++row) {
        for (size_t col = 0; col < dib_header.width; ++col) {
            file.write(reinterpret_cast<char*>(&pixels[row][col]), sizeof(Pixel));
        }
        for (int j = 0; j < (4 - dib_header.width * 3 % 4) % 4; ++j) {
            file.put(0);
        }
    }
}

Image::Image(const std::string& filename) {
    LoadImage(filename);
}