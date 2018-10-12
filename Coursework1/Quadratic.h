#pragma once
#include <iostream>

struct Coefficient {
	int a;
	int b;
	int c;
};
class Quadratic
{
public:
	Quadratic();
	~Quadratic();
	Coefficient cofficients;

	int getCoefficient(int power);
	int computeValue(int x);
	Quadratic operator+(const Quadratic& rhs);
	Quadratic operator-(const Quadratic& rhs);
	
};

std::ostream operator<<(std::ostream& outsream, const Quadratic& quad);
std::ostream operator>>(std::ostream& outsream, const Quadratic& quad);