#pragma once
struct Expression {
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
    explicit Polynomial(Polynomial &other);

    /**
     * Destructor that will delete the polynomial array of the heap
     */
    ~Polynomial();
    /**
     * Method to add an expression to the polynomial.
     * I.e adding 3x^2 to polynomial by doing addExpression(Expression(3,2)
     * @param expr
     */
    void addExpression(Expression expr);

    int getCoefficient(int degreeOfPower) const;

    float computeValue(float x) const;

    Polynomial operator+(Polynomial rhs);

    Polynomial operator-(Polynomial rhs);

    int getArraySize() const;

private:
    int arraySize = 0;
    Expression *polynomial;
};


