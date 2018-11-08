#pragma once

#include <iostream>

/**
 * Struct represent Coefficients in a Quadratic
 */
struct Coefficient {
    int a;
    int b;
    int c;

};
/**
 * enums to represent the powers of x in a quadratic equation
 * Values can be used
 */
enum PowerX {
    powerOfTwo = 2,
    powerOfOne = 1,
    powerOfZero = 0
};
/**
 * Class to represent a quadratic. This class 2 constructors.
 * internally, the Quadratic is represented by the  struct coefficient. Since this is a Quadratic class,
 * we know what the powers are so only need to store coefficient.
 */
class Quadratic {
public:
    /**
     * Constructor that takes a coefficient as a parameter. Coefficients an enum which stores 3 ints
     * @param coefficient
     */
    explicit Quadratic(Coefficient coefficient);

    /**
     * Constructor that initialises everything to 0
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

    friend std::ostream &operator<<(std::ostream &outStream, const Quadratic &quad);

    friend std::istream &operator>>(std::istream &inStream, Quadratic &quad);

private:
    Coefficient coefficients;
    const static char variable = 'x';


};




