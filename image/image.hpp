#include <string>
#include <cstdint>
#include <vector>

struct BmpHeader{
    uint16_t id_field;
    uint32_t file_size;
    uint32_t unused;
    uint32_t offset;
} __attribute__((packed));

struct DibHeader {
    uint32_t header_size;
    uint32_t width;
    uint32_t height;
    uint16_t color_planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t bitmap_size;
    uint32_t h_resolution;
    uint32_t v_resolution;
    uint32_t palette_size;
    uint32_t important_colors;
} __attribute__((packed));

class Image
{
private:
    void LoadImage(const std::string& filename);
public:
    struct Pixel {
        uint8_t blue;
        uint8_t green;
        uint8_t red;
    };
    void SaveImage(const std::string& filename);
    
    Image(const std::string& filename);

    BmpHeader bmp_header;
    DibHeader dib_header;
    std::vector<Pixel> pixels;
};
