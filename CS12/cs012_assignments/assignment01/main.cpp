//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn1/main.cpp 
/// @brief Assignment/Lab 1 for CS 12 q3 2015
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date April 6 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Lab Guy
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

double randFloat (double a, double b)
{
    /*This function generates a random double value between a and b*/
    
    return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

double rand_mv(double mean, double var)
{
    double x= mean - (sqrt(12.0 * var) / 2.0);
    double y= mean + (sqrt(12.0 * var) / 2.0);
    cout << x << " " << y << endl;
    return randFloat(x , y);
}

int main()
{
    srand(333);
    double mean;
    double var;
    cout << "Enter Mean: ";
    cin >> mean;
    cout << endl;
    cout << "Enter Variance: ";
    cin >> var;
    cout << endl;
    rand_mv(mean, var);
    
}