#include <iostream>
#include "utils/utils.hpp"
#include "filter_factory/filter_factory.hpp"

int main(int argc, char** argv) {
    ParsedData parsed = Parse(argc, argv);
    auto img = Image(parsed.input_path);
    FilterFactory factory;
    auto pipeline = factory.BuildPipeline(parsed);
    ApplyFilters(pipeline, img);
    img.SaveImage(parsed.output_path);
    return 0;
}