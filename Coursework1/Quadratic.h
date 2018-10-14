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

    float computeValue(float x);

    Quadratic operator+(Quadratic rhs);

    Quadratic operator-(Quadratic rhs);

    //TODO: work out right signature
    Quadratic operator+=(Quadratic rhs);

    Quadratic operator-=(Quadratic rhs);

    bool operator==(Quadratic rhs);

    bool operator!=(Quadratic rhs);


private:
    Coefficient cofficients;
};

std::ostream &operator<<(std::ostream &outstream, const Quadratic &quad);

std::istream &operator>>(std::istream &instream, Quadratic &quad);


