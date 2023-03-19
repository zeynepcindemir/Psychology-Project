#ifndef TARGET_HPP_
#define TARGET_HPP_

#include <iostream>
#include <string.h>

class Target
{

private:
    double x;
    double y;

public:
    double getX();
    void setX(double x);
    double getY();
    void setY(double y);
    std::string showCoordinates();

    Target();
    Target(double x, double y);
};

#endif