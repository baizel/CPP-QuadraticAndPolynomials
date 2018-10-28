#pragma once

#include <ostream>

/**
 * Struct to represent what a term is.
 * Each polynomial object has an array of term size
 */
struct Term {
    int coefficent;
    int powerOfX;

};

class Polynomial {
    /**
     * Class to represent a polynomial
     * @author Baizel
     */

public:

    /**
     * Default constructor
     */
    explicit Polynomial();

    /**
     * Copy constructor
     * This will copy the array over to a new array.
     */
    Polynomial(const Polynomial &other);

    /**
     * Destructor that will delete the polynomial array of the heap
     */
    ~Polynomial();

    /**
     * Method to add a Term to the polynomial.
     * I.e adding 3x^2 to polynomial by doing addTerm(Term(3,2)
     * Every time this is called a new array is made with size arraySize + 1.
     * @param term
     */
    void addTerm(Term term);

    int getCoefficient(int degreeOfPower) const;

    int getArraySize() const;

    float computeValue(float x) const;

    /********** Operator overloads ********/

    Polynomial operator+(const Polynomial &rhs) const;

    Polynomial operator-(const Polynomial &rhs) const;

    Polynomial operator*(const Polynomial &rhs) const;

    Polynomial &operator=(const Polynomial &rhs);

    Polynomial &operator+=(const Polynomial &rhs);

    Polynomial &operator-=(const Polynomial &rhs);

    Polynomial &operator*=(const Polynomial &rhs);

    bool operator==(const Polynomial &rhs) const;

    bool operator!=(const Polynomial &rhs) const;

    friend std::istream &operator>>(std::istream &inStream, Polynomial &polynomial);

    friend std::ostream &operator<<(std::ostream &outStream, const Polynomial &polynomial);

private:
    int arraySize = 0;
    Term *polynomial;

};





