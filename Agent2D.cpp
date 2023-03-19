
#include <iostream>
#include <iomanip>
#include <string.h>
#include <cmath>
#include "Agent2D.hpp"
#include "World2D.hpp"
#include "Vector.hpp"
#include "Target.hpp"

using namespace std;

// constructors
//  y:190, x:25-75
Agent2D::Agent2D()
{
    double radian = (std::rand() % 60 - 30) * 3.14 / 180;
    v.setI(-cos(radian));
    v.setJ(-sin(radian));
    this->x = 25 + (std::rand() % (75 - 25 + 1));
    this->y = (std::rand() % (190 + 1));
}

Agent2D::Agent2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

// getters and setters
double Agent2D::getX()
{
    return x;
}
void Agent2D::setX(double x)
{
    this->x = x;
}
double Agent2D::getY()
{
    return y;
}
void Agent2D::setY(double y)
{
    this->y = y;
}

Vector Agent2D::getVector()
{
    return this->v;
}
void Agent2D::setVector(Vector vct)
{
    this->v = vct;
}

// move method
void Agent2D::move(Vector v)
{
    this->setX(this->getX() + 2 * (v.getI()));
    this->setY(this->getY() + 2 * (v.getJ()));
}

// perceive mehod
double Agent2D::perceive(Target t, Agent2D a)
{
    return sqrt(pow(t.getX() - a.getX(), 2) + pow(t.getY() - a.getY(), 2) * 1.0);
}

// decide method
//  v1(t) = (1 - alpha) v2(t) + (alpha) v1(t)
Vector Agent2D::decide(Vector v1, Vector v2, double a)
{
    Vector newVct((1 - a) * v2.getI() + (a)*v1.getI(), (1 - a) * v2.getJ() + (a)*v1.getJ());
    this->setVector(newVct);
    return newVct;
}

// showCoordinates method
std::string Agent2D::showCoordinates()
{

    std::cout << "Agent's current location : (" << precision(x, 2) << "," << precision(y, 2) << ")\t"; // to write to the terminal
    std::string s = "Agent's current location: (" + precision(x, 2) + "," + precision(y, 2) + ")\t";   // to write to the .txt
    return s;
}

// precision method to fix the decimals
string Agent2D::precision(double x, int decDigits)
{
    stringstream ss;
    ss << fixed;
    ss.precision(decDigits); // set # places after decimal
    ss << x;
    return ss.str();
}

// checkCoordinates method to control boundary cases
bool Agent2D::checkCoordinates()
{

    if (x > World2D::WIDTH - 1 || y > World2D::HEIGHT - 1 || x < 0 || y < 0)
    {
        std::cout << "End of the game!\n"; // to write to the terminal
        return false;
        exit(0);
    }
    else
    {
        return true;
    }
}
