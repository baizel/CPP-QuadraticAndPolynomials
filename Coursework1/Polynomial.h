#pragma once
#include <ostream>

/**
 * Struct to represent what a term is.
 * Each polynomial object has an array of term size
 */
struct Term {
    int coefficient;
    int power;

};

class Polynomial {
    /**
     * Class to represent a polynomial.
     * The polynomial is made up of an array of Terms. (A Term is a struct that has a power and a coefficient.)
     * The array is on the heap. Starts with size 1 then expands when addTerm is used.
     *
     * @author Baizel
     */

public:

    /**
     * Default constructor. Initialise with array size 1
     */
    explicit Polynomial();

    /**
     * Copy constructor
     * This will copy the other.polynomial array over to a new array.
     */
    Polynomial(const Polynomial &other);

    /**
     * Destructor that will delete the polynomial array of the heap
     */
    ~Polynomial();

    /**
     * Method to add a Term to the polynomial.
     * I.e adding 3x^2 to polynomial by doing addTerm(Term{3,2})
     * Every time this is called a new array is made with size of arraySize + 1.
     * Uses std::copy to copy elements from one array to another
     * Note: If newTerm.power already exists then coefficient will get added onto the existing term
     * @param term
     */
    void addTerm(Term term);

    /**
     * Method to get the coefficient of a term given the power of x.
     * Will return 0 if it power does not exist
     * @param degreeOfPower (the power of x)
     * @return int 0 or value
     */
    int getCoefficient(int degreeOfPower) const;

    /**
     * Compute the value of the polynomial expression given x
     * @param x
     * @return an int
     */
    int computeValue(int x) const;

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

    /** These are friends so that polynomial array can be kept private */
    /**
     * Note: This uses cout to ask user for each term and how many terms to add
     * @param inStream
     * @param polynomial
     * @return inStream
     */
    friend std::istream &operator>>(std::istream &inStream, Polynomial &polynomial);
    /**
     * Method to display polynomial. Note: It will be in order of addition.
     * @param outStream
     * @param polynomial
     * @return outStream
     */
    friend std::ostream &operator<<(std::ostream &outStream, const Polynomial &polynomial);

private:
    //Keeps track of array size. Increments by 1 when using .addTerm
    int arraySize;

    //This will be initialised on the heap
    Term *polynomial;

};





