#pragma once

#include <iostream>

struct Coefficient {
    int a;
    int b;
    int c;

};

enum PowerX {
    powerOfTwo, powerOfOne, powerOfZero
};

class Quadratic {
public:
    explicit Quadratic(Coefficient coefficient);

    explicit Quadratic();

    ~Quadratic();

    int getCoefficient(PowerX power) const;

    int computeValue(int x) const;

    Quadratic operator+(Quadratic rhs);

    Quadratic operator-(Quadratic rhs);

    Quadratic &operator=(const Quadratic &rhs);

    Quadratic operator+=(const Quadratic &rhs);

    Quadratic operator-=(const Quadratic &rhs);

    bool operator==(const Quadratic &rhs);

    bool operator!=(const Quadratic &rhs);


private:
    Coefficient coefficients;
    const int PWR_TWO = 2;
    const int PWR_ONE = 1;
    const int PWR_ZERO = 0;
};

std::ostream &operator<<(std::ostream &outStream, const Quadratic &quad);

std::istream &operator>>(std::istream &inStream, Quadratic &quad);


