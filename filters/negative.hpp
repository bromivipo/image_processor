#include "base_filter.hpp"

class Negative : BaseFilter
{
public:
    Negative() {};

    void Apply(Image& img) override;
};
