#include <iostream>
#include "Quadratic.h"
#include "Polynomial.h"
#include <cassert>
#include <string>

using namespace std;

const int QUADRATIC_COEFFICIENT_A = 1;
const int QUADRATIC_COEFFICIENT_B = 2;
const int QUADRATIC_COEFFICIENT_C = 3;

// create x^2 + 2x + 3
Quadratic quadraticA(Coefficient{QUADRATIC_COEFFICIENT_A, QUADRATIC_COEFFICIENT_B, QUADRATIC_COEFFICIENT_C});
// create x^2 + 2x + 3
Quadratic quadraticB(Coefficient{QUADRATIC_COEFFICIENT_A, QUADRATIC_COEFFICIENT_B, QUADRATIC_COEFFICIENT_C});

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
    testQuadraticGetCoefficient();
    testQuadraticComputeValue();
    testQuadraticAddition();
    testQuadraticSubtraction();
    testQuadraticEquals();
    testQuadraticNotEquals();
    testQuadraticAdditionAssign();
    testQuadraticSubtractionAssign();
    testQuadraticCout();
}

void testQuadraticGetCoefficient() {
    assert(quadraticA.getCoefficient(PowerX::powerOfTwo) == QUADRATIC_COEFFICIENT_A);
    assert(quadraticA.getCoefficient(PowerX::powerOfOne) == QUADRATIC_COEFFICIENT_B);
    assert(quadraticA.getCoefficient(PowerX::powerOfZero) == QUADRATIC_COEFFICIENT_C);
}

void testQuadraticComputeValue() {
    float x = 2;
    float value = QUADRATIC_COEFFICIENT_A * pow(x, 2) +
                  QUADRATIC_COEFFICIENT_B * pow(x, 1) +
                  QUADRATIC_COEFFICIENT_C * pow(x, 0);

    assert(value == quadraticA.computeValue(x));
}

void testQuadraticAddition() {
    Quadratic q = quadraticA + quadraticB;
    assert(q.getCoefficient(PowerX::powerOfTwo) == (QUADRATIC_COEFFICIENT_A + QUADRATIC_COEFFICIENT_A));
    assert(q.getCoefficient(PowerX::powerOfOne) == (QUADRATIC_COEFFICIENT_B + QUADRATIC_COEFFICIENT_B));
    assert(q.getCoefficient(PowerX::powerOfZero) == (QUADRATIC_COEFFICIENT_C + QUADRATIC_COEFFICIENT_C));
}

void testQuadraticSubtraction() {
    Quadratic q = quadraticA - quadraticB;
    assert(q.getCoefficient(PowerX::powerOfTwo) == (QUADRATIC_COEFFICIENT_A - QUADRATIC_COEFFICIENT_A));
    assert(q.getCoefficient(PowerX::powerOfOne) == (QUADRATIC_COEFFICIENT_B - QUADRATIC_COEFFICIENT_B));
    assert(q.getCoefficient(PowerX::powerOfZero) == (QUADRATIC_COEFFICIENT_C - QUADRATIC_COEFFICIENT_C));
}

void testQuadraticEquals() {
    assert(quadraticA == quadraticB);
}

void testQuadraticNotEquals() {
    Quadratic notEquals(Coefficient{QUADRATIC_COEFFICIENT_C, QUADRATIC_COEFFICIENT_B, QUADRATIC_COEFFICIENT_A});
    assert(quadraticA != notEquals);
}

void testQuadraticAdditionAssign() {
    Quadratic plusEquals(Coefficient{QUADRATIC_COEFFICIENT_A,QUADRATIC_COEFFICIENT_B,QUADRATIC_COEFFICIENT_C});
    plusEquals += quadraticA;
    assert(plusEquals.getCoefficient(PowerX::powerOfTwo) == (QUADRATIC_COEFFICIENT_A + QUADRATIC_COEFFICIENT_A));
    assert(plusEquals.getCoefficient(PowerX::powerOfOne) == (QUADRATIC_COEFFICIENT_B + QUADRATIC_COEFFICIENT_B));
    assert(plusEquals.getCoefficient(PowerX::powerOfZero) == (QUADRATIC_COEFFICIENT_C + QUADRATIC_COEFFICIENT_C));

}

void testQuadraticSubtractionAssign() {
    Quadratic plusEquals(Coefficient{QUADRATIC_COEFFICIENT_A,QUADRATIC_COEFFICIENT_B,QUADRATIC_COEFFICIENT_C});
    plusEquals -= quadraticA;
    assert(plusEquals.getCoefficient(PowerX::powerOfTwo) == (QUADRATIC_COEFFICIENT_A - QUADRATIC_COEFFICIENT_A));
    assert(plusEquals.getCoefficient(PowerX::powerOfOne) == (QUADRATIC_COEFFICIENT_B - QUADRATIC_COEFFICIENT_B));
    assert(plusEquals.getCoefficient(PowerX::powerOfZero) == (QUADRATIC_COEFFICIENT_C - QUADRATIC_COEFFICIENT_C));
}

void testQuadraticCout() {
    std::cout << quadraticA;
}

void testQuadraticCin() {
    //TODO: How to do this
}

void testPolynomialGetCoefficient() {
    Polynomial p;
    p.addTerm(Term{1,2}); // x^2
}
