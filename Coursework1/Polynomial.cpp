#include "Polynomial.h"
#include <iostream>
#include <iterator>
#include <iterator>

Polynomial::Polynomial() {

}

void Polynomial::addExpression(Expression expr) {
    arraySize += 1;
    auto *temp = new Expression[arraySize];
    temp[arraySize-1] = expr;
    std::copy(polynomial, polynomial + (arraySize), stdext::checked_array_iterator<Expression *>(temp, arraySize));
    delete[]polynomial;
    polynomial = temp;
    std::cout <<" "<<polynomial[0].coefficent <<"asdasd a sd";
}

void Polynomial::print() {
    for (auto i = 0; i < arraySize; i++) {
        std::cout << polynomial[i].coefficent << "x" << "^" << polynomial[i].powerOfX << +" + ";
    }
    std::cout << std::endl;
}
