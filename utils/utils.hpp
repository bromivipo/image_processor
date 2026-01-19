#pragma once

#include <vector>
#include <optional>
#include <string>
#include <memory>
#include "../filters/base_filter.hpp"

using FilterPtr = std::unique_ptr<BaseFilter>;

struct FilterInfo {
    std::string name;
    std::vector<std::string> params;
};

struct ParsedData {
    std::string input_path;
    std::string output_path;
    std::vector<FilterInfo> filters;
};


ParsedData Parse(int argc, char** argv);
void ApplyFilters(const std::vector<FilterPtr>& filters, Image& img);