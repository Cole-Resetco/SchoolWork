//  =============== BEGIN ASSESSMENT HEADER ================
/// @file mathematics.cpp
/// @brief assignment06/Mathematics
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date March 1, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
 
using namespace std;
 
const int OK = 0;
const int DIV_ZERO = 1;
const int SQRT_ERR = 2;
 
int acquireOperands(const string &op, double &x, double &y, double &z)
{
    int numOp;
   
    if (op == "division" || op == "pythagorean" ||
    op == "quadratic")
    {
        cout << "Enter your first number: ";
        cin >> x;
        cout << endl;
       
        cout << "Enter your second number: ";
        cin >> y;
        cout << endl;
        numOp = 2;
    } else
    {
        cout << "Error: Operation not supported.\n";
    }
   
    if (op == "quadratic")
    {
        cout << "Enter your third number: ";
        cin >> z;
        cout << endl;
        numOp = 3;
    }
   
    return numOp;
    //cout << "aquireOperands FINISH ME" << endl;
}
 
double division(double &x, double &y, double &result)
{
    if (y == 0)
    {
        return DIV_ZERO;
    } else
    {
        result = x/y;
        return OK;
    }
}
 
double pythagorean(double &x, double &y, double &result)
{
    result = sqrt(pow(x, 2) + pow(y, 2));
    return OK;
}
 
double quadratic(double &x, double &y, double &z, double &result,
double &result2)
{
    if (x == 0)
    {
        return DIV_ZERO;
    } else if ((pow(y, 2) - (4 * x * z)) < 0)
    {
        return SQRT_ERR;
    } else
    {
        result = (-y + sqrt(y * y - 4 * x * z))/(2 * x);
        result2 = (-y - sqrt(y * y - 4 * x * z))/(2 * x);
        return OK;
    }
}
 
int main()
{
    double x = 12345.0;
    double y = 12345.0;
    double z = 12345.0;
    double result = 12345.0;
    double result2 = 12345.0;
    string op;
   
    do
    {
        cout << "Please choose an operation: ";
        cin >> op;
        cout << endl;
        acquireOperands(op, x, y, z);
    } while (x == 12345.0);
   
    if (op == "division")
    {
        if (division(x, y, result) == OK)
        {
            cout << "Equation: " << x << " / " << y << endl;
            cout << "Result: " << result << endl;
        }else if (division(x, y, result) == DIV_ZERO)
        {
            cout << "Equation: " << x << " / " << y << endl;
            cout << "Error: Cannot divide by zero.";
            cout << endl;
        }
    } else if (op == "pythagorean")
    {
        if (pythagorean(x, y, result) == OK)
        {
            cout << "Equation: " << "sqrt(" << x << "^2 + " << y << "^2)"
            << endl;
            cout << "Result: " << result << endl;
        }
    } else if (op == "quadratic")
    {
        if (quadratic(x, y, z, result, result2) == OK)
        {
            cout << "Equation: " << x << "x^2 + " << y << "x + " << z << " = 0";
            cout << endl;
            if (result == result2)
            {
                cout << "Result: " << result;
                cout << endl;
            } else
            {
                cout << "Result: " << result2 << ", " << result << endl;
            }
        } else if (quadratic(x, y, z, result, result2) == DIV_ZERO)
        {
            cout << "Equation: " << x << "x^2 + " << y << "x + " << z << " = 0"
            << endl;
            cout << "Error: Cannot divide by zero.";
            cout << endl;
        } else if (quadratic(x, y, z, result, result2) == SQRT_ERR)
        {
            cout << "Equation: " << x << "x^2 + " << y << "x + " << z << " = 0";
            cout << endl;
            cout << "Error: Cannot take square root of a negative number.";
            cout << endl;
        }
    }
   
    return 0;
}