/**
 * factorialX.cpp
 * 
 * this program computes the factorial of a number
 *
 * @s_egahi
 *
 * this is factorialX
 */

#include <iostream>

int factorial(int);

using namespace std;

int main(void)
{
    int num;

    cout << "Number: ";
    cin >> num;

    cout << "The factorial of " << num << " is " << factorial(num) << ".\n";
    return 0;
}

/**
 * calculates the factorial of a number using recursion
 * returns the answer
 */
int factorial(int num)
{
    if (num == 1 || num == 0)
        return 1;

    else
        return num * factorial(num - 1);
}