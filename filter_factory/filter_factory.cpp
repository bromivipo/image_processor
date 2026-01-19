#include "filter_factory.hpp"

#include <iostream>

#include "../filters/blur.hpp"
#include "../filters/flip.hpp"
#include "../filters/grayscale.hpp"
#include "../filters/negative.hpp"
#include "../filters/rotate.hpp"
#include "../filters/scale.hpp"
#include "../filters/sharpening.hpp"
#include "../filters/threshold.hpp"


void FilterFactory::RegisterFilter(std::string name, FilterCreator creator) {
    creators_[name] = creator;
}

FilterFactory::FilterFactory() {
    RegisterFilter("blur", [](const std::vector<std::string>& args) {
        return std::make_unique<Blur>();
    });
    RegisterFilter("flip", [](const std::vector<std::string>& args) {
        return std::make_unique<Flip>();
    });
    RegisterFilter("grayscale", [](const std::vector<std::string>& args) {
        return std::make_unique<Grayscale>();
    });
    RegisterFilter("negative", [](const std::vector<std::string>& args) {
        return std::make_unique<Negative>();
    });
    RegisterFilter("rotate", [](const std::vector<std::string>& args) {
        return std::make_unique<Rotate>();
    });
    RegisterFilter("scale", [](const std::vector<std::string>& args) {
        if (args.empty()) {
            throw std::runtime_error("Scale filter requires one argument");
        }
        try {
            double koef = std::stod(args[0]);
            return std::make_unique<Scale>(koef);
        } catch (const std::invalid_argument& e) {
            throw std::runtime_error("Scale argument must be a number! Got: " + args[0]);
        }
    });
    RegisterFilter("sharpening", [](const std::vector<std::string>& args) {
        return std::make_unique<Sharpening>();
    });
    RegisterFilter("threshold", [](const std::vector<std::string>& args) {
        return std::make_unique<Threshold>();
    });
}

std::vector<FilterPtr> FilterFactory::BuildPipeline(const ParsedData& data) {
    std::vector<FilterPtr> filter_ptrs;
    for (const auto& filter : data.filters) {
        if (!creators_.contains(filter.name)) {
            std::cout << "Unsupported filter name: " << filter.name << std::endl;
            continue;
        }
        filter_ptrs.push_back(creators_[filter.name](filter.params));
    }
    return filter_ptrs;
}