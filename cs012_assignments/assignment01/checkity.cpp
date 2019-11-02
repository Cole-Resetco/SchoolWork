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
    
    double a = 0.5;
    
    double b = 3.5;
    
    cin >> a;
    cin >> b;
    

    /*for (int i = 0; i < 21; i++ )
    {
       cout << randFloat(a , b) << " ";
    }
    */
    std::cout << std::fixed;
    std::cout<< std::setprecision(1)  << static_cast<double>(a+b)/2 << " ";
    
    int arrSize = 1000;
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
    cout  << mean << " ";
    
    std::cout<< std::setprecision(2) <<  (((b-a)*(b-a))/12) << " ";
    
    for (int i = 0; i <= arrSize; i++)
    {
        varSum = varSum + ((arr[i] - mean) * (arr[i] - mean)); 
    }
    
    std::cout<< std::setprecision(2) << (varSum/ arrSize) << " ";
    cout << endl;
    
    
    //-----------------------------------------------------//
    //                     Series 2                        // 
    
    std::cout<< std::setprecision(1)  << static_cast<double>(a+b)/2 << " ";
    
    arrSize = 100000;
    
    sum = 0;
    double arr2[arrSize];
    
    for( int i = 0; i <= arrSize; i++)
    {
        arr2[i] = randFloat(a, b);
        sum = sum + randFloat(a, b);
        //cout << sum << endl;
        //cout << arr[i];
    }
    
    
    mean = 0;
    varSum = 0;
    mean = sum / arrSize;
    cout  << mean << " ";
    
    std::cout<< std::setprecision(2) <<(((b-a)*(b-a))/12) << " ";
    
    for (int i = 0; i <= arrSize; i++)
    {
        varSum = varSum + ((arr2[i] - mean) * (arr2[i] - mean)); 
    }
    
    cout << (varSum/ arrSize);
    
    
    
    return 0;
}