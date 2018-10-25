#include "Polynomial.h"
#include <iostream>
#include <iterator>
#include <iterator>

Polynomial::Polynomial() {
    polynomial = new Term[1];
}

Polynomial::Polynomial(const Polynomial &other) {
    this->arraySize = other.arraySize;
    polynomial = new Term[other.getArraySize()];
    for (int i = 0; i < other.getArraySize(); i++) {
        polynomial[i] = Term{other.polynomial[i].coefficent, other.polynomial[i].powerOfX};
    }
}

Polynomial::~Polynomial() {
    delete[] polynomial;
}

void Polynomial::addTerm(Term term) {
    if (term.coefficent != 0) {
        if (getCoefficient(term.powerOfX) != 0) {
            for (int i = 0; i < arraySize; i++) {
                if (polynomial[i].powerOfX == term.powerOfX) {
                    polynomial[i].coefficent += term.coefficent;
                    // Break out the function
                    return;
                }
            }
        }
        if (arraySize == 0) {
            polynomial[0] = term;
            arraySize = 1;
        } else {
            arraySize++;
            auto *temp = new Term[arraySize];
            std::copy(polynomial, polynomial + (arraySize),
                      stdext::checked_array_iterator<Term *>(temp, arraySize));
            delete[]polynomial;
            polynomial = temp;
            polynomial[arraySize - 1] = term;
        }
    }
}

int Polynomial::getCoefficient(int degreeOfPower) const {
    for (int i = 0; i < arraySize; i++) {
        if (polynomial[i].powerOfX == degreeOfPower) {
            return polynomial[i].coefficent;
        }
    }
    return 0;
}

float Polynomial::computeValue(float x) const {
    float total = 0.0f;
    for (int i = 0; i < arraySize; i++) {
        total += polynomial[i].coefficent * (pow(x, polynomial[i].powerOfX));
    }
    return total;
}

int Polynomial::getArraySize() const {
    return arraySize;
}

Polynomial Polynomial::operator+(const Polynomial &rhs) {
    Polynomial ret = Polynomial(rhs);
    for (int i = 0; i < arraySize; i++) {
        bool added = false;
        for (int j = 0; j < ret.getArraySize(); j++) {
            if (polynomial[i].powerOfX == ret.polynomial[j].powerOfX) {
                int cof = polynomial[i].coefficent + ret.polynomial[j].coefficent;
                ret.polynomial[j].coefficent = cof;
                added = true;
            }
        }
        if (!added) {
            ret.addTerm(Term{polynomial[i].coefficent, polynomial[i].powerOfX});
        }
    }
    return ret;
}

Polynomial Polynomial::operator-(const Polynomial &rhs) {
    Polynomial ret = Polynomial(rhs);
    for (int i = 0; i < arraySize; i++) {
        bool added = false;
        for (int j = 0; j < ret.getArraySize(); j++) {
            if (polynomial[i].powerOfX == ret.polynomial[j].powerOfX) {
                int cof = polynomial[i].coefficent - ret.polynomial[j].coefficent;
                ret.polynomial[j].coefficent = cof;
                added = true;
            }
        }
        if (!added) {
            ret.addTerm(Term{polynomial[i].coefficent, polynomial[i].powerOfX});
        }
    }
    return ret;
}

Polynomial Polynomial::operator*(const Polynomial &rhs) {
    Polynomial ret = Polynomial(rhs);
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < ret.getArraySize(); j++) {
            int cof = polynomial[i].coefficent * ret.polynomial[j].coefficent;
            int ind = polynomial[i].powerOfX + ret.polynomial[j].powerOfX;
            ret.polynomial[j] = Term({cof, ind});
        }
    }
    return ret;
}

Polynomial &Polynomial::operator=(const Polynomial &rhs) {
    delete[] polynomial;
    polynomial = new Term[rhs.arraySize];
    for (int i = 0; i < rhs.arraySize; i++) {
        polynomial[i] = Term({rhs.polynomial[i].coefficent, rhs.polynomial[i].powerOfX});
    }
    return *this;
}

Polynomial &Polynomial::operator+=(const Polynomial &rhs) {
    Polynomial ret = *this + rhs;
    *this = ret;
    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &rhs) {
    Polynomial ret = *this - rhs;
    *this = ret;
    return *this;
}

Polynomial &Polynomial::operator*=(const Polynomial &rhs) {
    Polynomial ret = *this * rhs;
    *this = ret;
    return *this;
}

bool Polynomial::operator==(const Polynomial &rhs) {
    bool ret = false;
    if (arraySize == rhs.arraySize) {
        ret = true;
        for (int i = 0; i < arraySize; i++) {
            ret *= getCoefficient(polynomial[i].powerOfX) == rhs.getCoefficient(polynomial[i].powerOfX);
        }
    }
    return ret;
}

bool Polynomial::operator!=(const Polynomial &rhs) {
    return !(*this == rhs);
}

std::ostream &operator<<(std::ostream &outStream, const Polynomial &polynomial) {
    for (auto i = 0; i < polynomial.getArraySize(); i++) {
        std::cout << polynomial.polynomial[i].coefficent;
        if (polynomial.polynomial[i].powerOfX != 0) {
            std::cout << "x";
            if (polynomial.polynomial[i].powerOfX != 1) {
                std::cout << "^" << polynomial.polynomial[i].powerOfX;
            }
        }

        if (i != polynomial.getArraySize() - 1) {
            if (polynomial.polynomial[i + 1].coefficent >= 0) {
                std::cout << " + ";
            } else {
                std::cout << " ";
            }
        }
    }
    return outStream;
}

std::istream &operator>>(std::istream &inStream, Polynomial &polynomial) {
    int max;
    std::cout << "How many terms would you like to add? ";
    inStream >> max;
    for (int i = 0; i < max; i++) {
        int cof, power;
        std::cout << "First term Coefficient: ";
        inStream >> cof;

        std::cout << "First term Power: ";
        inStream >> power;

        polynomial.addTerm(Term{cof,power});

    }
    return inStream;
}








