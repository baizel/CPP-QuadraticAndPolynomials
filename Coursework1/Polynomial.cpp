#include "Polynomial.h"
#include <iostream>
#include <iterator>

Polynomial::Polynomial() : arraySize(0), polynomial(new Term[1]) {}

Polynomial::Polynomial(const Polynomial &other) : arraySize(other.arraySize), polynomial(new Term[other.arraySize]) {
    for (int i = 0; i < other.arraySize; i++) {
        polynomial[i] = Term{other.polynomial[i].coefficient, other.polynomial[i].power};
    }
}

Polynomial::~Polynomial() {
    delete[] polynomial;
    polynomial = nullptr;
}

void Polynomial::addTerm(Term term) {
    if (term.coefficient != 0) {
        // Checks if Term already exists adds coefficient if it does
        if (getCoefficient(term.power) != 0) {
            for (int i = 0; i < arraySize; i++) {
                if (polynomial[i].power == term.power) {
                    polynomial[i].coefficient += term.coefficient;
                    return; // Break out the function early
                }
            }
        }
        if (arraySize == 0) {
            //Special case at the start where we don't need to expand the array
            polynomial[0] = term;
            arraySize = 1;
        } else {
            // stdext::checked_array_iterator is used to stop compiler warning
            arraySize++;
            auto *temp = new Term[arraySize];
            std::copy(polynomial, polynomial + arraySize,
                      stdext::checked_array_iterator<Term *>(temp, arraySize));
            delete[]polynomial;
            polynomial = temp;
            polynomial[arraySize - 1] = term;
        }
    }
}

int Polynomial::getCoefficient(int degreeOfPower) const {
    for (int i = 0; i < arraySize; i++) {
        if (polynomial[i].power == degreeOfPower) {
            return polynomial[i].coefficient;
        }
    }
    return 0;
}

int Polynomial::computeValue(int x) const {
    int total = 0;
    for (int i = 0; i < arraySize; i++) {
        total += polynomial[i].coefficient * ((int) pow(x, polynomial[i].power));
    }
    return total;
}


Polynomial Polynomial::operator+(const Polynomial &rhs) const {
    Polynomial returnPoly = Polynomial(rhs);
    for (int i = 0; i < arraySize; i++) {
        bool added = false;
        for (int j = 0; j < returnPoly.arraySize; j++) {
            if (polynomial[i].power == returnPoly.polynomial[j].power) {
                int cof = polynomial[i].coefficient + returnPoly.polynomial[j].coefficient;
                returnPoly.polynomial[j].coefficient = cof;
                added = true;
            }
        }
        if (!added) {
            returnPoly.addTerm(Term{polynomial[i].coefficient, polynomial[i].power});
        }
    }
    return returnPoly;
}

Polynomial Polynomial::operator-(const Polynomial &rhs) const {
    //Multiply by -1 and add self
    Polynomial returnPoly = Polynomial(rhs);
    for (int i = 0; i < returnPoly.arraySize; i++) {
        returnPoly.polynomial[i].coefficient = returnPoly.polynomial[i].coefficient * -1;
    }
    return *this + returnPoly;
}

Polynomial Polynomial::operator*(const Polynomial &rhs) const {
    Polynomial returnPoly;
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < rhs.arraySize; j++) {
            int cof = polynomial[i].coefficient * rhs.polynomial[j].coefficient;
            int ind = polynomial[i].power + rhs.polynomial[j].power;
            returnPoly.addTerm(Term({cof, ind}));
        }
    }
    return returnPoly;
}

Polynomial &Polynomial::operator=(const Polynomial &rhs) {
    arraySize = rhs.arraySize;
    delete[] polynomial;
    polynomial = new Term[rhs.arraySize];
    for (int i = 0; i < rhs.arraySize; i++) {
        polynomial[i] = Term({rhs.polynomial[i].coefficient, rhs.polynomial[i].power});
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

bool Polynomial::operator==(const Polynomial &rhs) const {
    // Assumes false will always be 0 and true will always be 1 (C++ standards)
    // Using an int as boolean so i can do multiplication with 1 and 0
    int ret = false;
    if (arraySize == rhs.arraySize) {
        ret = true;
        for (int i = 0; i < arraySize && ret; i++) {
            //Breaks out the loop and returns false if anything evaluates to false
            ret *= getCoefficient(polynomial[i].power) == rhs.getCoefficient(polynomial[i].power);
        }
    }
    return (bool) ret;
}

bool Polynomial::operator!=(const Polynomial &rhs) const {
    return !(*this == rhs);
}

std::ostream &operator<<(std::ostream &outStream, const Polynomial &polynomial) {
    for (int i = 0; i < polynomial.arraySize; i++) {
        outStream << polynomial.polynomial[i].coefficient;
        if (polynomial.polynomial[i].power != 0) {
            outStream << "x";
            if (polynomial.polynomial[i].power != 1) {
                outStream << "^" << polynomial.polynomial[i].power;
            }
        }

        if (i != polynomial.arraySize - 1) {
            if (polynomial.polynomial[i + 1].coefficient >= 0) {
                outStream << " + ";
            } else {
                outStream << " ";
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

        polynomial.addTerm(Term{cof, power});

    }
    return inStream;
}








