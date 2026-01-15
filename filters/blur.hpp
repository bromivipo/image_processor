#include "base_filter.hpp"

class Blur : BaseFilter
{
public:
    Blur() {};

    void Apply(Image& img) override;
};
