#pragma once

#include <iostream>

struct Coefficient {
    int a;
    int b;
    int c;

};

enum PowerX {
    powerOfTwo, powerOfOne, powerOfZero
};

class Quadratic {
public:
    /**
     * Constructor that takes a coefficient as a parameter. Coefficients an enum which stores 3 ints
     * @param coefficient
     */
    explicit Quadratic(Coefficient coefficient);

    /**
     * Default constructor that initialises everything to 0
     */
    explicit Quadratic();

    /**
     * Default destructor.
     */
    ~Quadratic();

    /**
     * method to return a coefficient given the power of x.
     * @param power as an enum
     * @return an int which is the coefficient a, b or c.
     */
    int getCoefficient(PowerX power) const;

    /**
     * Method to calculate value of quadratic given the value of x
     * @param x as an int
     * @return the value
     */
    int computeValue(int x) const;

    /** Overload operators **/
    Quadratic operator+(Quadratic rhs);

    Quadratic operator-(Quadratic rhs);

    Quadratic &operator=(const Quadratic &rhs);

    Quadratic operator+=(const Quadratic &rhs);

    Quadratic operator-=(const Quadratic &rhs);

    bool operator==(const Quadratic &rhs);

    bool operator!=(const Quadratic &rhs);


private:
    Coefficient coefficients;
    const int PWR_TWO = 2;
    const int PWR_ONE = 1;
    const int PWR_ZERO = 0;
};

std::ostream &operator<<(std::ostream &outStream, const Quadratic &quad);

std::istream &operator>>(std::istream &inStream, Quadratic &quad);


