#pragma once

#include <unordered_map>
#include <memory>
#include <functional>
#include "../utils/utils.hpp"
#include "../filters/base_filter.hpp"

using FilterPtr = std::unique_ptr<BaseFilter>;
using FilterCreator = std::function<FilterPtr(const std::vector<std::string>&)>;

class FilterFactory {
private:
    void RegisterFilter(std::string name, FilterCreator creator);

    std::unordered_map<std::string, FilterCreator> creators_;
public:
    FilterFactory();
    std::vector<FilterPtr> BuildPipeline(const ParsedData& data);
};


