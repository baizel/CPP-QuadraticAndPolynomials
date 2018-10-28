#include <iostream>
#include "Quadratic.h"
#include "Polynomial.h"
#include <cassert>
#include <string>
#include <sstream>

using namespace std;

const int QUADRATIC_COEFFICIENT_A = 1;
const int QUADRATIC_COEFFICIENT_B = 2;
const int QUADRATIC_COEFFICIENT_C = 3;

// create x^2 + 2x + 3
Quadratic quadraticA(Coefficient{QUADRATIC_COEFFICIENT_A, QUADRATIC_COEFFICIENT_B, QUADRATIC_COEFFICIENT_C});
// create x^2 + 2x + 3
Quadratic quadraticB(Coefficient{QUADRATIC_COEFFICIENT_A, QUADRATIC_COEFFICIENT_B, QUADRATIC_COEFFICIENT_C});


Polynomial p;

void initPolynomial() {
    p.addTerm(Term{5, 0}); // 5x^0 -> 5
    p.addTerm(Term{2, 1}); // 2x^1 -> 2x
    p.addTerm(Term{1, 2}); // x^2
    p.addTerm(Term{2, 3}); // 2x^3
    p.addTerm(Term{3, 3}); // 3x^3
    p.addTerm(Term{4, 4}); // 4x^4
}

void testQuadraticGetCoefficient();

void testQuadraticComputeValue();

void testQuadraticAddition();

void testQuadraticSubtraction();

void testQuadraticEquals();

void testQuadraticNotEquals();

void testQuadraticAdditionAssign();

void testQuadraticSubtractionAssign();

void testQuadraticCout();

void testQuadraticCin();

/** Polynomial Tests **/
void testPolynomialGetCoefficient();

void testPolynomialComputeValue();

void testPolynomialAddition();

void testPolynomialSubtraction();

void testPolynomialEquals();

void testPolynomialNotEquals();

void testPolynomialAdditionAssign();

void testPolynomialSubtractionAssign();

void testPolynomialCout();

int main() {
    initPolynomial();
    testQuadraticGetCoefficient();
    testQuadraticComputeValue();
    testQuadraticAddition();
    testQuadraticSubtraction();
    testQuadraticEquals();
    testQuadraticNotEquals();
    testQuadraticAdditionAssign();
    testQuadraticSubtractionAssign();
    testQuadraticCout();
    // Polynomial Tests
    testPolynomialGetCoefficient();
    testPolynomialComputeValue();
}

void testQuadraticGetCoefficient() {
    assert(quadraticA.getCoefficient(PowerX::powerOfTwo) == QUADRATIC_COEFFICIENT_A);
    assert(quadraticA.getCoefficient(PowerX::powerOfOne) == QUADRATIC_COEFFICIENT_B);
    assert(quadraticA.getCoefficient(PowerX::powerOfZero) == QUADRATIC_COEFFICIENT_C);
    std::cout << "testQuadraticGetCoefficient Passed" << std::endl;
}

void testQuadraticComputeValue() {
    float x = 2;
    float value = QUADRATIC_COEFFICIENT_A * pow(x, 2) +
                  QUADRATIC_COEFFICIENT_B * pow(x, 1) +
                  QUADRATIC_COEFFICIENT_C * pow(x, 0);

    assert(value == quadraticA.computeValue(x));
    std::cout << "testQuadraticComputeValue Passed" << std::endl;
}

void testQuadraticAddition() {
    Quadratic q = quadraticA + quadraticB;
    assert(q.getCoefficient(PowerX::powerOfTwo) == (QUADRATIC_COEFFICIENT_A + QUADRATIC_COEFFICIENT_A));
    assert(q.getCoefficient(PowerX::powerOfOne) == (QUADRATIC_COEFFICIENT_B + QUADRATIC_COEFFICIENT_B));
    assert(q.getCoefficient(PowerX::powerOfZero) == (QUADRATIC_COEFFICIENT_C + QUADRATIC_COEFFICIENT_C));
    std::cout << "testQuadraticAddition Passed" << std::endl;

}

void testQuadraticSubtraction() {
    Quadratic q = quadraticA - quadraticB;
    assert(q.getCoefficient(PowerX::powerOfTwo) == (QUADRATIC_COEFFICIENT_A - QUADRATIC_COEFFICIENT_A));
    assert(q.getCoefficient(PowerX::powerOfOne) == (QUADRATIC_COEFFICIENT_B - QUADRATIC_COEFFICIENT_B));
    assert(q.getCoefficient(PowerX::powerOfZero) == (QUADRATIC_COEFFICIENT_C - QUADRATIC_COEFFICIENT_C));
    std::cout << "testQuadraticSubtraction Passed" << std::endl;

}

void testQuadraticEquals() {
    assert(quadraticA == quadraticB);
    std::cout << "testQuadraticEquals Passed" << std::endl;

}

void testQuadraticNotEquals() {
    Quadratic notEquals(Coefficient{QUADRATIC_COEFFICIENT_C, QUADRATIC_COEFFICIENT_B, QUADRATIC_COEFFICIENT_A});
    assert(quadraticA != notEquals);
    std::cout << "testQuadraticNotEquals Passed" << std::endl;

}

void testQuadraticAdditionAssign() {
    Quadratic plusEquals(Coefficient{QUADRATIC_COEFFICIENT_A, QUADRATIC_COEFFICIENT_B, QUADRATIC_COEFFICIENT_C});
    plusEquals += quadraticA;
    assert(plusEquals.getCoefficient(PowerX::powerOfTwo) == (QUADRATIC_COEFFICIENT_A + QUADRATIC_COEFFICIENT_A));
    assert(plusEquals.getCoefficient(PowerX::powerOfOne) == (QUADRATIC_COEFFICIENT_B + QUADRATIC_COEFFICIENT_B));
    assert(plusEquals.getCoefficient(PowerX::powerOfZero) == (QUADRATIC_COEFFICIENT_C + QUADRATIC_COEFFICIENT_C));
    std::cout << "testQuadraticAdditionAssign Passed" << std::endl;

}

void testQuadraticSubtractionAssign() {
    Quadratic plusEquals(Coefficient{QUADRATIC_COEFFICIENT_A, QUADRATIC_COEFFICIENT_B, QUADRATIC_COEFFICIENT_C});
    plusEquals -= quadraticA;
    assert(plusEquals.getCoefficient(PowerX::powerOfTwo) == (QUADRATIC_COEFFICIENT_A - QUADRATIC_COEFFICIENT_A));
    assert(plusEquals.getCoefficient(PowerX::powerOfOne) == (QUADRATIC_COEFFICIENT_B - QUADRATIC_COEFFICIENT_B));
    assert(plusEquals.getCoefficient(PowerX::powerOfZero) == (QUADRATIC_COEFFICIENT_C - QUADRATIC_COEFFICIENT_C));
    std::cout << "testQuadraticSubtractionAssign Passed" << std::endl;
}

void testQuadraticCout() {
    std::stringstream out;
    out << quadraticA;
    assert(out.str() == "1x^2 + 2x + 3");
    std::cout << "testQuadraticCout Passed" << std::endl;
}

void testQuadraticCin() {
    //TODO: How to do this
}

void testPolynomialGetCoefficient() {
    assert(p.getCoefficient(0) == 5);
    assert(p.getCoefficient(2) == 1);
    assert(p.getCoefficient(3) == 5);
    assert(p.getCoefficient(1) == 2);
    assert(p.getCoefficient(4) == 4);
    assert(p.getCoefficient(100) == 0);
    std::cout << "testPolynomialGetCoefficient Passed" << std::endl;

}

void testPolynomialComputeValue() {
    float x = 2;
    float value = 5 + (2 * x) + pow(x, 2) + (5 * (pow(x, 3))) + (4 * (pow(x, 4)));
    assert(p.computeValue(x) == value);
    std::cout << "testPolynomialComputeValue Passed" << std::endl;
}
