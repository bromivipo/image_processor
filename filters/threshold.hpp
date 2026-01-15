#include "base_filter.hpp"

class Threshold : BaseFilter
{
public:
    Threshold() {};

    void Apply(Image& img) override;
};
