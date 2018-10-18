#include "Quadratic.h"


Quadratic::Quadratic(Coefficient coefficient) {
    cofficients = coefficient;
}

Quadratic::~Quadratic() = default;

int Quadratic::getCoefficient(PowerX power) const {
    switch (power) {
        case powerOfTwo:
            return cofficients.a;
        case powerOfOne:
            return cofficients.b;
        case powerOfZero:
            return cofficients.c;
        default:
            //Throw an exception here
            break;
    }

}

float Quadratic::computeValue(float x) const {
    return cofficients.a * (pow(x, PWR_TWO)) + cofficients.b * (pow(x, PWR_ONE)) + cofficients.c;
}

Quadratic Quadratic::operator+(Quadratic rhs) {

    int a = cofficients.a + rhs.getCoefficient(PowerX::powerOfTwo);
    int b = cofficients.b + rhs.getCoefficient(PowerX::powerOfOne);
    int c = cofficients.c + rhs.getCoefficient(PowerX::powerOfZero);

    return Quadratic(Coefficient{a, b, c});
}

Quadratic Quadratic::operator-(Quadratic rhs) {

    int a = cofficients.a - rhs.getCoefficient(PowerX::powerOfTwo);
    int b = cofficients.b - rhs.getCoefficient(PowerX::powerOfOne);
    int c = cofficients.c - rhs.getCoefficient(PowerX::powerOfZero);

    return Quadratic(Coefficient{a, b, c});
}

Quadratic& Quadratic::operator=(const Quadratic &rhs) {
    cofficients.a = rhs.getCoefficient(powerOfTwo);
    cofficients.b = rhs.getCoefficient(powerOfOne);
    cofficients.c = rhs.getCoefficient(powerOfZero);
    return *this;
}


std::ostream &operator<<(std::ostream &outstream, const Quadratic &quad) {
    outstream << quad.getCoefficient(PowerX::powerOfTwo) << "x^2 + "
              << quad.getCoefficient(PowerX::powerOfOne) << "x + "
              << quad.getCoefficient(PowerX::powerOfZero) << std::endl;

    return outstream;
}

std::istream &operator>>(std::istream &instream, Quadratic &quad) {
    int a, b, c;
    instream >> a >> b >> c;
    quad = Quadratic(Coefficient{a, b, c});
    return instream;
}


