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

    ~Quadratic();

    int getCoefficient(PowerX power) const;

    float computeValue(float x) const;

    Quadratic operator+(Quadratic rhs);

    Quadratic operator-(Quadratic rhs);


    Quadratic &operator=(const Quadratic &rhs);

    //TODO: work out right signature
    Quadratic operator+=(Quadratic rhs);

    Quadratic operator-=(Quadratic rhs);

    bool operator==(Quadratic rhs);

    bool operator!=(Quadratic rhs);


private:
    Coefficient cofficients;
    const int PWR_TWO = 2;
    const int PWR_ONE = 1;
    const int PWR_ZERO = 0;
};

std::ostream &operator<<(std::ostream &outstream, const Quadratic &quad);

std::istream &operator>>(std::istream &instream, Quadratic &quad);


