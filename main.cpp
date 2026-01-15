#include <iostream>
#include "filters/grayscale.hpp"
#include "filters/scale.hpp"
#include "filters/negative.hpp"
#include "filters/threshold.hpp"
#include "filters/blur.hpp"
#include "filters/sharpening.hpp"
#include "filters/flip.hpp"
#include "filters/rotate.hpp"

int main(int argc, char** argv) {
    Image img("C:\\Users\\misha\\Documents\\image_processor\\bmp_images\\image24.bmp");
    auto filter = Rotate();
    filter.Apply(img);
    img.SaveImage("C:\\Users\\misha\\Documents\\image_processor\\bmp_images\\output.bmp");
    return 0;
}