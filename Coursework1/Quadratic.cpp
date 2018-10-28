#include "Quadratic.h"


Quadratic::Quadratic(Coefficient coefficient) {
    cofficients = coefficient;
}

Quadratic::Quadratic() {
    cofficients = Coefficient{0, 0, 0};
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
            return NULL;
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

Quadratic &Quadratic::operator=(const Quadratic &rhs) {
    cofficients.a = rhs.getCoefficient(powerOfTwo);
    cofficients.b = rhs.getCoefficient(powerOfOne);
    cofficients.c = rhs.getCoefficient(powerOfZero);
    return *this;
}

Quadratic Quadratic::operator+=(const Quadratic &rhs) {
    this->cofficients.a += rhs.cofficients.a;
    this->cofficients.b += rhs.cofficients.b;
    this->cofficients.c += rhs.cofficients.c;
    return *this;
}

Quadratic Quadratic::operator-=(const Quadratic &rhs) {
    this->cofficients.a -= rhs.cofficients.a;
    this->cofficients.b -= rhs.cofficients.b;
    this->cofficients.c -= rhs.cofficients.c;
    return *this;
}

bool Quadratic::operator==(const Quadratic &rhs) {
    return this->cofficients.a == rhs.cofficients.a
           && this->cofficients.b == rhs.cofficients.b
           && this->cofficients.c == rhs.cofficients.c;
}

bool Quadratic::operator!=(const Quadratic &rhs) {
    return this->cofficients.a != rhs.cofficients.a
           || this->cofficients.b != rhs.cofficients.b
           || this->cofficients.c != rhs.cofficients.c;
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
    std::cout << "Input coefficient A for power of 2";
    inStream >> a;
    std::cout << "Input coefficient B for power of 1";
    inStream >> b;
    std::cout << "Input coefficient C for power of 01";
    inStream >> c;
    quad = Quadratic(Coefficient{a, b, c});
    return inStream;
}


