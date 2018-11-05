#include "Quadratic.h"


Quadratic::Quadratic(Coefficient coefficient) : coefficients(coefficient) {}

Quadratic::Quadratic() : coefficients(Coefficient{0, 0, 0}) {}

Quadratic::~Quadratic() = default;

int Quadratic::getCoefficient(PowerX power) const {
    switch (power) {
        case powerOfTwo:
            return coefficients.a;
        case powerOfOne:
            return coefficients.b;
        case powerOfZero:
            return coefficients.c;
        default:
            return NULL;
    }

}

int Quadratic::computeValue(int x) const {
    return coefficients.a * ((int) pow(x, PWR_TWO)) + coefficients.b * ((int) pow(x, PWR_ONE)) + coefficients.c;
}

Quadratic Quadratic::operator+(Quadratic rhs) {

    int a = coefficients.a + rhs.getCoefficient(PowerX::powerOfTwo);
    int b = coefficients.b + rhs.getCoefficient(PowerX::powerOfOne);
    int c = coefficients.c + rhs.getCoefficient(PowerX::powerOfZero);

    return Quadratic(Coefficient{a, b, c});
}

Quadratic Quadratic::operator-(Quadratic rhs) {

    int a = coefficients.a - rhs.getCoefficient(PowerX::powerOfTwo);
    int b = coefficients.b - rhs.getCoefficient(PowerX::powerOfOne);
    int c = coefficients.c - rhs.getCoefficient(PowerX::powerOfZero);

    return Quadratic(Coefficient{a, b, c});
}

Quadratic &Quadratic::operator=(const Quadratic &rhs) {
    coefficients.a = rhs.getCoefficient(powerOfTwo);
    coefficients.b = rhs.getCoefficient(powerOfOne);
    coefficients.c = rhs.getCoefficient(powerOfZero);
    return *this;
}

Quadratic Quadratic::operator+=(const Quadratic &rhs) {
    this->coefficients.a += rhs.coefficients.a;
    this->coefficients.b += rhs.coefficients.b;
    this->coefficients.c += rhs.coefficients.c;
    return *this;
}

Quadratic Quadratic::operator-=(const Quadratic &rhs) {
    this->coefficients.a -= rhs.coefficients.a;
    this->coefficients.b -= rhs.coefficients.b;
    this->coefficients.c -= rhs.coefficients.c;
    return *this;
}

bool Quadratic::operator==(const Quadratic &rhs) {
    return this->coefficients.a == rhs.coefficients.a
           && this->coefficients.b == rhs.coefficients.b
           && this->coefficients.c == rhs.coefficients.c;
}

bool Quadratic::operator!=(const Quadratic &rhs) {
    return this->coefficients.a != rhs.coefficients.a
           || this->coefficients.b != rhs.coefficients.b
           || this->coefficients.c != rhs.coefficients.c;
}


std::ostream &operator<<(std::ostream &outStream, const Quadratic &quad) {
    outStream << quad.getCoefficient(PowerX::powerOfTwo) << "x^2"
              << ((quad.getCoefficient(powerOfOne) > 0) ? " + " : " ")
              << quad.getCoefficient(PowerX::powerOfOne) << "x"
              << ((quad.getCoefficient(powerOfZero) > 0) ? " + " : " ")
              << quad.getCoefficient(PowerX::powerOfZero);

    return outStream;
}

std::istream &operator>>(std::istream &inStream, Quadratic &quad) {
    int a, b, c;
    std::cout << "Input coefficients A for power of 2";
    inStream >> a;
    std::cout << "Input coefficients B for power of 1";
    inStream >> b;
    std::cout << "Input coefficients C for power of 01";
    inStream >> c;
    quad = Quadratic(Coefficient{a, b, c});
    return inStream;
}


