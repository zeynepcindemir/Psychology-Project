
#ifndef AGENT2D_HPP_
#define AGENT2D_HPP_

#include <iostream>
#include <string.h>
#include "Target.hpp"
#include "Vector.hpp"

using namespace std;

class Agent2D
{

private:
    Vector v;
    double x;
    double y;

public:
    const static int HEIGHT = 5;
    const static int WIDTH = 5;
    Vector getVector();
    void setVector(Vector vct);
    double getX();
    void setX(double x);
    double getY();
    void setY(double y);
    static string precision(double x, int decDigits);

    void move(Vector v);

    Agent2D();
    Agent2D(double x, double y);

    std::string showCoordinates();
    bool checkCoordinates();
    double perceive(Target t, Agent2D a);
    Vector decide(Vector v1, Vector v2, double a);
};

#endif
