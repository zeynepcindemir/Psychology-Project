#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string.h>
#include "World2D.hpp"
#include "Agent2D.hpp"
#include "Target.hpp"
#include "Vector.hpp"

using namespace std;
// distanceVec method
static Vector distanceVec(Target t, Agent2D a)
{
    return Vector(t.getX() - a.getX(), t.getY() - a.getY());
}
// main method
int main()
{

    int k = 0;
    while (k != 100)
    {
        Agent2D a;
        Target t;

        Vector v1 = distanceVec(t, a);
        Vector v2(5, 9);

        for (int i = 0; i < 100; i++)
        {
            v2 = a.decide(v1, v2, 0.80);
            if (a.checkCoordinates())
            {
                a.move(v2);
            }
            v1 = distanceVec(t, a);

            ofstream outfile("output.80.txt", ios::app);
            // to write to the .txt
            outfile << a.showCoordinates() << t.showCoordinates() << "Distance between target and agent: " << Agent2D::precision(a.perceive(t, a), 2) << "\n";
        }

        if (a.perceive(t, a) < 1 || abs(a.getX() - t.getX()) < 1 || abs(a.getY() - t.getY()) < 1)
        {
            std::cout << "Achieved the target!\n"; // to write to the terminal
        }

        k++;
    }

    return 0;
}
