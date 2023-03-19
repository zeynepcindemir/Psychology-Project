#include <iostream>
#include <string.h>
#include "Target.hpp"
#include "Agent2D.hpp"

using namespace std;

// constructors
//  y:5, x:35-65
Target::Target()
{
    this->x = 35 + (rand() % (65 - 35 + 1));
    this->y = (rand() % (5 + 1));
    ;
}

Target::Target(double x, double y)
{
    this->x = x;
    this->y = y;
}
// getters and setters
double Target::getX()
{
    return this->x;
}
void Target::setX(double x)
{
    this->x = x;
}
double Target::getY()
{
    return this->y;
}
void Target::setY(double y)
{
    this->y = y;
}
// showCoordinates method
std::string Target::showCoordinates()
{
    std::cout << "Target's current location: (" << Agent2D::precision(x, 2) << "," << Agent2D::precision(y, 2) << ")\t"; // to write to the terminal
    std::string s = "Target's current location: (" + Agent2D::precision(x, 2) + "," + Agent2D::precision(y, 2) + ")\t";  // to write to the .txt
    return s;
}