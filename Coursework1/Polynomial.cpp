#include "Polynomial.h"
#include <iostream>
#include <iterator>
#include <iterator>

Polynomial::Polynomial() {
    polynomial = new Expression[1];
}

Polynomial::Polynomial(const Polynomial &other) {
    this->arraySize = other.arraySize;
    polynomial = new Expression[other.getArraySize()];
    for (int i = 0; i < other.getArraySize(); i++) {
         polynomial[i] = Expression{other.polynomial[i].coefficent, other.polynomial[i].powerOfX};
    }
}

Polynomial::~Polynomial() {
    delete[] polynomial;
}

void Polynomial::addExpression(Expression expr) {
    if (expr.coefficent != 0) {
        if (arraySize == 0) {
            polynomial[0] = expr;
            arraySize = 1;
        } else {
            arraySize++;
            auto *temp = new Expression[arraySize];
            std::copy(polynomial, polynomial + (arraySize),
                      stdext::checked_array_iterator<Expression *>(temp, arraySize));
            delete[]polynomial;
            polynomial = temp;
            polynomial[arraySize - 1] = expr;
        }
    }
}

void Polynomial::print() {
    //TODO: Change this to >> operator
    for (auto i = 0; i < arraySize; i++) {
        if (polynomial[i].coefficent != 0) {
            std::cout << polynomial[i].coefficent;
        }
        if (polynomial[i].powerOfX != 0) {
            std::cout << "x";
            if (polynomial[i].powerOfX != 1) {
                std::cout << "^" << polynomial[i].powerOfX;
            }
        }

        if (i != arraySize - 1) {
            if (polynomial[i + 1].coefficent >= 0) {
                std::cout << " + ";
            } else {
                std::cout << " ";
            }
        }
    }
    std::cout << std::endl;
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

Polynomial *Polynomial::operator+(const Polynomial &rhs) {
    Polynomial *ret = new Polynomial(rhs);
    for (int i = 0; i < arraySize; i++) {
        bool added = false;
        for (int j = 0; j < ret->getArraySize(); j++) {
            if (polynomial[i].powerOfX == ret->polynomial[j].powerOfX) {
                int cof = polynomial[i].coefficent + ret->polynomial[j].coefficent;
                ret->polynomial[i].coefficent = cof;
                added = true;
            }
        }
        if (!added) {
            ret->addExpression(Expression{polynomial[i].coefficent, polynomial[i].powerOfX});
        }
    }
    return ret;
}

//Polynomial *Polynomial::operator-(Polynomial *rhs) {
//    return nullptr;
//}

