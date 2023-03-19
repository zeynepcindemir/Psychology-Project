#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <iostream>
using namespace std;

class Vector
{

private:
    double i;
    double j;

public:
    Vector();

    Vector(double iNew, double jNew);

    double getI();

    double getJ();

    void setI(double iNew);

    void setJ(double jNew);

    void makeUnit();
};

#endif