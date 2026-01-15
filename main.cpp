#include <iostream>
#include "filters/grayscale.hpp"
#include "filters/scale.hpp"
#include "filters/negative.hpp"
#include "filters/threshold.hpp"

int main(int argc, char** argv) {
    Image img("C:\\Users\\misha\\Documents\\image_processor\\bmp_images\\image24.bmp");
    auto filter = Threshold();
    filter.Apply(img);
    img.SaveImage("C:\\Users\\misha\\Documents\\image_processor\\bmp_images\\output.bmp");
    return 0;
}