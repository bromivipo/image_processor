#include "base_filter.hpp"

class Threshold : BaseFilter
{
public:
    void Apply(Image& img) override;
};
