#include "utils.hpp"

#include <iostream>

ParsedData Parse(int argc, char** argv) {
    if (argc < 3) {
        std::runtime_error("Wrong args! Usage: " + std::string(argv[0]) + " input.bmp output.bmp [-filter1 params] [-filter2 params]...");
    }
    ParsedData parsed;
    parsed.input_path = argv[1];
    parsed.output_path = argv[2];
    FilterInfo filter;
    for (size_t i = 3; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (!filter.name.empty()) {
                parsed.filters.push_back(filter);
            }
            filter.name = std::string(argv[i]).substr(1);
            filter.params.clear();
        } else {
            if (filter.name.empty()) {
                std::runtime_error("Wrong args! Usage: " + std::string(argv[0]) + " input.bmp output.bmp [-filter1 params] [-filter2 params]...");
            }
            filter.params.push_back(argv[i]);
        }
    }
    if (!filter.name.empty()) {
        parsed.filters.push_back(filter);
    }
    return parsed;
}

void ApplyFilters(const std::vector<FilterPtr>& filters, Image& img) {
    for (auto& filter : filters) {
        filter->Apply(img);
    }
}