#include <iostream>

#include "RpnCalculator.hpp"

int main()
{
    RpnCalculator rpnCalculator{};
    std::cout << rpnCalculator.compute("30 10 20 + * 20 /") << std::endl;
}
