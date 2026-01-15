#include "base_filter.hpp"

class Negative : BaseFilter
{
public:
    void Apply(Image& img) override;
};
