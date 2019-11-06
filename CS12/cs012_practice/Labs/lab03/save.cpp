//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn2/main.cpp 
/// @brief Assignment/Lab 3 for CS 12 quarter 3 year 2015
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date April 14 2015
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
#include <fstream>
#include <cstdlib>

using namespace std;

const int Q = 2;
const int R = 3;
const int S = 3;

void matrixMult(int a[][R], int b[][S], int product[][S])
{
    int i;
    int j;
    int k;
    int sum = 0;
    
    cout << "Res: " << endl;
    for(i = 0; i < Q; i++)
    {
        for(j = 0; j < S; j++)
        {
            for(k = 0; k < R; k++)
            {
                sum = sum + (a[i][k] * b[k][j]);
                //cout << "i: " << i << "j: " << j << "k: " << k << "sum: " 
                //<<  sum << "* ";

            }
            product[i][j] = sum;
            sum = 0;
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a[Q][R];
    int b[R][S];
    int product[Q][S];
    int i;
    int j;
    
    
    
    cout << "Enter Matrix A(size 2x3): ";
    for(i = 0; i < Q; i++)
    {
        for(j = 0; j < R; j++)
        {
            cin >> a[i][j];
        }
    }
    
    cout << "Enter Matrix B(size 3x3): ";
    for(i = 0; i < R; i++)
    {
        for(j = 0; j < S; j++)
        {
            cin >> b[i][j];
        }
    }
    
    matrixMult(a, b, product);
    
    return 0;
}