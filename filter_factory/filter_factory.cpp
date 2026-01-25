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
        if (args.empty()) {
            throw std::runtime_error("Flip filter requires one argument");
        }
        if (args[0] != "v" && args[0] != "h") {
            throw std::runtime_error("Wrong flip argument! Allowed values: v and h");
        }
        return std::make_unique<Flip>(args[0][0]);
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
            if (koef < 0.1 || koef > 10.0) {
                throw std::out_of_range("Koef out of  range (0.1-10.0)");
            }
            return std::make_unique<Scale>(koef);
        } catch (const std::invalid_argument& e) {
            throw std::runtime_error("Scale argument must be a float! Got: " + args[0]);
        }
    });
    RegisterFilter("sharpening", [](const std::vector<std::string>& args) {
        return std::make_unique<Sharpening>();
    });
    RegisterFilter("threshold", [](const std::vector<std::string>& args) {
        if (args.empty()) {
            throw std::runtime_error("Threshold filter requires one argument");
        }
        try {
            int limit = std::stoi(args[0]);
            if (limit < 0 || limit > 255) {
                throw std::out_of_range("Limit out of uint8 range (0-255)");
            }
            return std::make_unique<Threshold>(static_cast<uint8_t>(limit));
        } catch (const std::invalid_argument& e) {
            throw std::runtime_error("Threshold argument must be an integer! Got: " + args[0]);
        }
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