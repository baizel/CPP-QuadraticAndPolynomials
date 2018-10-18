#include <iostream>
#include "Quadratic.h"
#include "Polynomial.h"

using namespace std;
int main() {
    Quadratic quadratic(Coefficient{2, 1, 5});
    cout << quadratic.getCoefficient(powerOfTwo) << endl;
    cout << quadratic.getCoefficient(powerOfOne) << endl;
    cout << quadratic.getCoefficient(powerOfZero) << endl;

    cout << quadratic.computeValue(2.2f) << endl;

    cout << quadratic + Quadratic(Coefficient{2, 2, 1});

    Polynomial poly;
    poly.addExpression(Expression{6,3});
    poly.addExpression(Expression{4,2});
    poly.addExpression(Expression{3,1});
    poly.addExpression(Expression{10,0});
    poly.print();
    cin.get();

}