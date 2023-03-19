#include "Vector.hpp"
#include <iostream>
#include <cmath>
using namespace std;

// constructors
Vector::Vector() {}

Vector::Vector(double i, double j)
{
    this->i = i;
    this->j = j;
    this->makeUnit();
}
// getters and setters
double Vector::getI()
{
    return i;
}

double Vector::getJ()
{
    return j;
}

void Vector::setI(double i)
{
    this->i = i;
}

void Vector::setJ(double j)
{
    this->j = j;
}
// makeUnit method to convert this vector to unit vector
void Vector::makeUnit()
{
    double length = sqrt((this->i) * (this->i) + (this->j) * (this->j));

    this->setI(this->i / length);
    this->setJ(this->j / length);
}
