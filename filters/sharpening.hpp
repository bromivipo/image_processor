#include "base_filter.hpp"

class Sharpening : BaseFilter
{
public:
    void Apply(Image& img) override;
};
