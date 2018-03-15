/**
 * triangle.cpp
 *
 * this program takes the dimensions of a triangle
 * determines if its a right angle triangle
 * computes it's area and circumference.
 *
 * this was triangle!
 */

#include <iostream>
#include <cmath>        // needed for squareroot function

using namespace std;

int main(void)
{
    // triangle dimensions
    int a, b, c;

    cout << "Enter each figure and press enter\n";

    cout << "a: ";
    cin >> a;
    cout  << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    // ensure c is the highest of the 3 numbers.
    if (a > c)
    {
        // a is greater than c swap them
        int temp = a;
        a = c;
        c = temp;
    }
    if (b > c)
    {
        // b is greater than c swap them
        int temp = b;
        b = c;
        c = temp;
    }

    // for right angle triangle
    // a^2 + b^2 = c^2;
    if (a*a + b*b == c*c)
    {
        cout << "This is a right angle triangle.\n";
    }
    else
    {
        cout << "This is not a right angle triangle.\n";
    }

    // circumference = sum of sides
    cout << "Circumference = " << a + b + c << " units\n";

    // area using heron's formula
    int s = (a + b + c) / 2;
    cout << "Area = " << sqrt(s * (s - a) * (s - b) * (s - c)) << " squared units\n";

    // success
    return 0;
}