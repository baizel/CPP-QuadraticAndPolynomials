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


Polynomial polynomial;

void initPolynomial() {
    polynomial.addTerm(Term{4, 4}); // 4x^4
    polynomial.addTerm(Term{3, 3}); // 3x^3
    polynomial.addTerm(Term{2, 3}); // 2x^3
    polynomial.addTerm(Term{1, 2}); // x^2
    polynomial.addTerm(Term{2, 1}); // 2x^1 -> 2x
    polynomial.addTerm(Term{5, 0}); // 5x^0 -> 5
    // polynomial = 4x^4 + 5x^3 + x^2 + 2x + 5
}

void testQuadraticGetCoefficient();

void testQuadraticComputeValue();

void testQuadraticAddition();

void testQuadraticSubtraction();

void testQuadraticEquality();

void testQuadraticNotEquals();

void testQuadraticAssignment();

void testQuadraticAdditionAssign();

void testQuadraticSubtractionAssign();

void testQuadraticCout();

/** Polynomial Tests **/
void testPolynomialGetCoefficient();

void testPolynomialComputeValue();

void testPolynomialAddition();

void testPolynomialSubtraction();

void testPolynomialMultiply();

void testPolynomialEquality();

void testPolynomialNotEquals();

void testPolynomialAssignment();

void testPolynomialAdditionAssign();

void testPolynomialSubtractionAssign();

void testPolynomialMultiplyAssign();

void testPolynomialCopyConstructor();

void testPolynomialCout();

int main() {
    initPolynomial();
    std::cout << "Start Quadratic Tests" << std::endl;
    testQuadraticGetCoefficient();
    testQuadraticComputeValue();
    testQuadraticAddition();
    testQuadraticSubtraction();
    testQuadraticEquality();
    testQuadraticNotEquals();
    testQuadraticAssignment();
    testQuadraticAdditionAssign();
    testQuadraticSubtractionAssign();
    testQuadraticCout();

    std::cout << std::endl << "Start Polynomial Tests" << std::endl;
    testPolynomialGetCoefficient();
    testPolynomialComputeValue();
    testPolynomialAddition();
    testPolynomialSubtraction();
    testPolynomialMultiply();
    testPolynomialEquality();
    testPolynomialNotEquals();
    testPolynomialAssignment();
    testPolynomialAdditionAssign();
    testPolynomialSubtractionAssign();
    testPolynomialMultiplyAssign();
    testPolynomialCopyConstructor();
    testPolynomialCout();

    //TODO: Test cin
}

void testQuadraticGetCoefficient() {
    assert(quadraticA.getCoefficient(PowerX::powerOfTwo) == QUADRATIC_COEFFICIENT_A);
    assert(quadraticA.getCoefficient(PowerX::powerOfOne) == QUADRATIC_COEFFICIENT_B);
    assert(quadraticA.getCoefficient(PowerX::powerOfZero) == QUADRATIC_COEFFICIENT_C);
    std::cout << "testQuadraticGetCoefficient Passed" << std::endl;
}

void testQuadraticComputeValue() {
    int x = 2;
    int value = QUADRATIC_COEFFICIENT_A * (int) pow(x, 2) +
                QUADRATIC_COEFFICIENT_B * (int) pow(x, 1) +
                QUADRATIC_COEFFICIENT_C * (int) pow(x, 0);

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

void testQuadraticEquality() {
    assert(quadraticA == quadraticB);
    std::cout << "testQuadraticEquality Passed" << std::endl;

}

void testQuadraticNotEquals() {
    Quadratic notEquals(Coefficient{QUADRATIC_COEFFICIENT_C, QUADRATIC_COEFFICIENT_B, QUADRATIC_COEFFICIENT_A});
    assert(quadraticA != notEquals);
    std::cout << "testQuadraticNotEquals Passed" << std::endl;

}

void testQuadraticAssignment() {
    Quadratic same = quadraticA;
    assert(same.getCoefficient(PowerX::powerOfTwo) == (QUADRATIC_COEFFICIENT_A));
    assert(same.getCoefficient(PowerX::powerOfOne) == (QUADRATIC_COEFFICIENT_B));
    assert(same.getCoefficient(PowerX::powerOfZero) == (QUADRATIC_COEFFICIENT_C));
    std::cout << "testQuadraticAssignment Passed" << std::endl;
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

void testPolynomialGetCoefficient() {
    assert(polynomial.getCoefficient(0) == 5);
    assert(polynomial.getCoefficient(2) == 1);
    assert(polynomial.getCoefficient(3) == 5);
    assert(polynomial.getCoefficient(1) == 2);
    assert(polynomial.getCoefficient(4) == 4);
    assert(polynomial.getCoefficient(100) == 0);
    std::cout << "testPolynomialGetCoefficient Passed" << std::endl;

}

void testPolynomialComputeValue() {
    int x = 4;
    int value = 5 + (2 * x) + (int) pow(x, 2) + (5 * ((int) pow(x, 3))) + (4 * ((int) pow(x, 4)));
    assert(polynomial.computeValue(x) == value);
    std::cout << "testPolynomialComputeValue Passed" << std::endl;
}

void testPolynomialAddition() {
    // polynomial = 4x^4 + 5x^3 + x^2 + 2x + 5
    Polynomial p;
    p.addTerm(Term{12, 0}); // + 12
    p.addTerm(Term{1, 2}); // x^2
    p.addTerm(Term{-2, 3}); // -2x^3
    auto res = p + polynomial;

    assert(res.getCoefficient(0) == (12 + 5));
    assert(res.getCoefficient(1) == (0 + 2));
    assert(res.getCoefficient(2) == (1 + 1));
    assert(res.getCoefficient(3) == (-2 + 5));
    assert(res.getCoefficient(4) == (0 + 4));

    std::cout << "testPolynomialAddition Passed" << std::endl;

}

void testPolynomialSubtraction() {
    // polynomial = 4x^4 + 5x^3 + x^2 + 2x + 5
    Polynomial p;
    p.addTerm(Term{12, 0});
    p.addTerm(Term{1, 2});
    p.addTerm(Term{-2, 3});
    auto res = p - polynomial;

    assert(res.getCoefficient(0) == (12 - 5));
    assert(res.getCoefficient(1) == (0 - 2));
    assert(res.getCoefficient(2) == (1 - 1));
    assert(res.getCoefficient(3) == (-2 - 5));
    assert(res.getCoefficient(4) == (0 - 4));

    std::cout << "testPolynomialSubtraction Passed" << std::endl;
}

void testPolynomialMultiply() {
    Polynomial test = (polynomial * polynomial);
    Polynomial result;

    // (4x^4 + 5x^3 + 1x^2 + 2x + 5) * (4x^4 + 5x^3 + 1x^2 + 2x + 5)
    // Result from http://www.wolframalpha.com
    result.addTerm(Term{16, 8});
    result.addTerm(Term{40, 7});
    result.addTerm(Term{33, 6});
    result.addTerm(Term{26, 5});
    result.addTerm(Term{61, 4});
    result.addTerm(Term{54, 3});
    result.addTerm(Term{14, 2});
    result.addTerm(Term{20, 1});
    result.addTerm(Term{25, 0});

    assert(test == result);
    std::cout << "testPolynomialMultiply Passed" << std::endl;

}

void testPolynomialEquality() {
    Polynomial p;
    p.addTerm(Term{4, 4});
    p.addTerm(Term{3, 3});
    p.addTerm(Term{2, 3});
    p.addTerm(Term{1, 2});
    p.addTerm(Term{2, 1});
    p.addTerm(Term{5, 0});
    assert(p == polynomial);
    std::cout << "testPolynomialEquality Passed" << std::endl;

}

void testPolynomialNotEquals() {
    Polynomial p;
    p.addTerm(Term{3, 4});
    p.addTerm(Term{3, 3});
    assert(p != polynomial);
    std::cout << "testPolynomialNotEquals Passed" << std::endl;
}

void testPolynomialAssignment() {
    Polynomial p = polynomial;
    assert(p == polynomial);
    std::cout << "testPolynomialAssignment Passed" << std::endl;
}

void testPolynomialAdditionAssign() {
    Polynomial p;
    int a = 3;
    int b = 4;
    p.addTerm(Term{a, 4}); // 3x^4
    p.addTerm(Term{b, 3}); // 4x^3

    Polynomial q;
    q.addTerm(Term{3, 4}); // 3x^4
    q.addTerm(Term{3, 3}); // 3x^3
    q.addTerm(Term{3, 2}); // 3x^2

    Polynomial result;
    result.addTerm(Term{a + 3, 4});
    result.addTerm(Term{b + 3, 3});
    result.addTerm(Term{3, 2});
    p += q;

    assert(result == p);
    std::cout << "testPolynomialAdditionAssign Passed" << std::endl;

}

void testPolynomialMultiplyAssign() {
    Polynomial p;
    p.addTerm(Term{3, 2});
    p *= p;

    Polynomial result;
    result.addTerm(Term{9, 4});

    assert(p == result);
    std::cout << "testPolynomialMultiplyAssign Passed" << std::endl;

}

void testPolynomialSubtractionAssign() {
    int p_a = 2;
    int p_b = 2;

    int q_a = 3;
    int q_b = 4;

    Polynomial p;
    p.addTerm(Term{p_a, 4});
    p.addTerm(Term{p_b, 3});

    Polynomial q;
    q.addTerm(Term{q_a, 4});
    q.addTerm(Term{q_b, 3});
    q.addTerm(Term{3, 2});

    Polynomial result;
    result.addTerm(Term{p_a - q_a, 4});
    result.addTerm(Term{p_b - q_b, 3});
    result.addTerm(Term{0 - 3, 2});
    p -= q;

    assert(result == p);
    std::cout << "testPolynomialSubtractionAssign Passed" << std::endl;
}

void testPolynomialCopyConstructor() {
    Polynomial p = Polynomial(polynomial);
    assert(p == polynomial);
    std::cout << "testPolynomialCopyConstructor Passed" << std::endl;

}

void testPolynomialCout() {
    std::stringstream out;
    out << polynomial;
    assert(out.str() == "4x^4 + 5x^3 + 1x^2 + 2x + 5");
    std::cout << "testPolynomialCout Passed" << std::endl;
}
