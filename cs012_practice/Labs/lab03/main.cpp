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
#include <ctime>
 
using namespace std;
 
const int Q = 2;
const int R = 3;
const int S = 3;
 
void matrixMult(const int a[][R], const int b[][S], int product[][S])
{
    for (int i = 0; i < Q; ++i)
    {
        for (int j = 0; j < S; ++j)
        {
            int result = 0;
            for (int k = 0; k < R; ++k)
            {
                result += (a[i][k] * b[k][j]);
            }
            product[i][j] = result;
            if ((j + 1) % S == 0)
            {
                cout << product[i][j] << endl;
            }
            else
            {
                cout << product[i][j] << " ";
            }
        }
    }
}
 
int main()
{
    int matA[Q][R] = {0};
    int matB[S][R] = {0};
    int product[Q][R] = {0};
    int input;
    cout << "Gimme a Matrix of (2 x 3): ";
    for (int i = 0; i < Q; ++i)
    {
        for (int j = 0; j < R; ++j)
        {
            cin >> input;
            matA[i][j] = input;
        }
    }
   
    cout << "Gimme a Matrix of (3 x 3): ";
    for (int i = 0; i < Q; ++i)
    {
        for (int j = 0; j < S; ++j)
        {
            cin >> input;
            matB[i][j] = input;
        }
    }
    cout << "Res: " << endl;
    matrixMult(matA, matB, product);
    return 0;
}