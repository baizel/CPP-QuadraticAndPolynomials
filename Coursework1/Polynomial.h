#pragma once

#include <ostream>

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
    void print();

    /**
     * Default constructor
     */
    explicit Polynomial();

    /**
     * Copy constructor
     */
    Polynomial(const Polynomial &other);

    /**
     * Destructor that will delete the polynomial array of the heap
     */
    ~Polynomial();

    /**
     * Method to add a Term to the polynomial.
     * I.e adding 3x^2 to polynomial by doing addTerm(Term(3,2)
     * @param term
     */
    void addTerm(Term term);

    int getCoefficient(int degreeOfPower) const;

    int getArraySize() const;

    float computeValue(float x) const;

    /********** Operator overloads ********/

    Polynomial operator+(const Polynomial &rhs);

    Polynomial operator-(const Polynomial &rhs);

    Polynomial operator*(const Polynomial &rhs);

    Polynomial &operator=(const Polynomial &rhs);

    Polynomial &operator+=(const Polynomial &rhs);

    Polynomial &operator-=(const Polynomial &rhs);

    Polynomial &operator*=(const Polynomial &rhs);

    bool operator==(const Polynomial &rhs);

    bool operator!=(const Polynomial &rhs);

    friend std::istream &operator>>(std::istream &inStream, Polynomial &polynomial);

    friend std::ostream &operator<<(std::ostream &outStream, const Polynomial &polynomial);

private:
    int arraySize = 0;
    Term *polynomial;

};





