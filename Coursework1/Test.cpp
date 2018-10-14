#include <iostream>
#include "Quadratic.h"

int main() {
    Quadratic quadratic(Coefficient{2, 1, 5});
    std::cout << quadratic.getCoefficient(powerOfTwo) << std::endl;
    std::cout << quadratic.getCoefficient(powerOfOne) << std::endl;
    std::cout << quadratic.getCoefficient(powerOfZero) << std::endl;

    std::cout << quadratic.computeValue(2.2f) << std::endl;

    std::cout << quadratic + Quadratic(Coefficient{2, 2, 1});

    std::cin.get();

}