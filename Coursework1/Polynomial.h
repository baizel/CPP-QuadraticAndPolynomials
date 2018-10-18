#pragma once
struct Expression {
    int coefficent;
    int powerOfX;

};

class Polynomial {

public:
    void print();
    explicit Polynomial();

    ~Polynomial() = default;

    void addExpression(Expression expr);

    int getCoefficient(int degreeOfPower) const;

    float computeValue(float x) const;

    Polynomial operator+(Polynomial rhs);

    Polynomial operator-(Polynomial rhs);

private:
    int arraySize = 0;
    Expression* polynomial = new Expression[0];
};


