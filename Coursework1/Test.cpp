#include <iostream>
#include "Quadratic.h"
#include "Polynomial.h"

using namespace std;

int main() {
    Quadratic quadratic(Coefficient{0, 1, 5});
    cout << quadratic.getCoefficient(powerOfTwo) << endl;
    cout << quadratic.getCoefficient(powerOfOne) << endl;
    cout << quadratic.getCoefficient(powerOfZero) << endl;

    cout << quadratic.computeValue(2.2f) << endl;

    cout << quadratic << std::endl << Quadratic(Coefficient{5, 9, -3}) << std::endl;
    Polynomial* poly = new Polynomial();
    Polynomial* polyb = new Polynomial();
    poly->addExpression(Expression{6, 3});
    poly->addExpression(Expression{-4, 2});
    polyb->addExpression(Expression{-1, 1});
    polyb->addExpression(Expression{-10, 0});
    std::cout << poly + polyb;

    cin.get();

}