#include "base_filter.hpp"

class Grayscale : BaseFilter
{
public:
    Grayscale() {};

    void Apply(Image& img) override;
};
