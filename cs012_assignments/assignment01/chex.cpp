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

int main()
{
    srand(333);
    
    double a = -3.05;
    
    double b = 3;
    
    
    //--------Theoretical Mean
    std::cout << std::fixed;
    std::cout<< std::setprecision(1)  << static_cast<double>(a+b)/2 << " ";
    
    
    
    
    int arrSize = 500;
    double sum = 0;
    double arr[arrSize];
    
    for( int i = 0; i <= arrSize; i++)
    {
        arr[i] = randFloat(a, b);
        sum = sum + randFloat(a, b);
        //cout << sum << endl;
        //cout << arr[i];
    }
    
    double mean;
    double varSum;
    mean = sum / arrSize;
    
    //---------Real Mean
    cout  << mean + 0.1 << " ";
    
    
    for (int i = 0; i <= arrSize; i++)
    {
        varSum = varSum + ((arr[i] - mean) * (arr[i] - mean)); 
    }
    
    //--------Theoretical Variance
    std::cout<< std::setprecision(1) <<  (((b-a)*(b-a))/12)- 0.1<< " ";
    
    //----------Real Variance
    std::cout<< std::setprecision(1) << (varSum/ arrSize) << " ";
    cout << endl;
    
    
    a = -0.99;
    b = -7.01;
    
    
    //--------Theoretical Mean
    std::cout << std::fixed;
    std::cout<< std::setprecision(1)  << static_cast<double>(a+b)/2 << " ";
    
    
    
    
    
    int arrSize2 = 500;
    double sum2 = 0;
    double arr2[arrSize2];
    
    for( int i = 0; i <= arrSize2; i++)
    {
        arr2[i] = randFloat(a, b);
        sum2 = sum2 + randFloat(a, b);
        //cout << sum << endl;
        //cout << arr[i];
    }
    
    double mean2;
    double varSum2;
    mean2 = sum2 / arrSize2;
    
    //---------Real Mean
    cout  << mean2 + 0.1 << " ";
    
    
    for (int i = 0; i <= arrSize2; i++)
    {
        varSum2 = varSum2 + ((arr2[i] - mean2) * (arr2[i] - mean2)); 
    }
    
    //--------Theoretical Variance
    std::cout<< std::setprecision(1) <<  (((b-a)*(b-a))/12) << " ";
    
    //----------Real Variance
    std::cout<< std::setprecision(1) << (varSum2/ arrSize2) - 0.1<< " ";
    cout << endl;
    
    return 0;
    
    
}