#include <iostream>
#include "Quadratic.h"
#include "Polynomial.h"

using namespace std;

int main() {
//    Quadratic quadratic(Coefficient{1,2,3});
//    Quadratic qb(Coefficient{1,2,3});
//    std::cout << quadratic << std::endl;
//
//    std::cout << (quadratic  != qb)<<std::endl;
//    cout << quadratic.getCoefficient(powerOfTwo) << endl;
//    cout << quadratic.getCoefficient(powerOfOne) << endl;
//    cout << quadratic.getCoefficient(powerOfZero) << endl;
//
//    cout << quadratic.computeValue(2.2f) << endl;
//
//    cout << quadratic << std::endl << Quadratic(Coefficient{5, 9, -3}) << std::endl;

    Polynomial* poly = new Polynomial();
    Polynomial* polyb = new Polynomial();

//    poly->addTerm(Term{5, 3});
    poly->addTerm(Term{4, 2});

//    polyb->addTerm(Term{5, 3});
    polyb->addTerm(Term{3, 2});
    Polynomial& p = *poly ;
    std::cout << p;
//  (*poly - *polyb);
//  std::cout<<poly->getCoefficient(3) << " " << polyb->computeValue(2)  << std::endl;

    cin.get();

}