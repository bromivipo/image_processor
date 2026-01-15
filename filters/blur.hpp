#include "base_filter.hpp"

class Blur : BaseFilter
{
public:
    void Apply(Image& img) override;
};
