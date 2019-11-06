//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn2/main.cpp 
/// @brief Assignment/Lab 2 for CS 12 quarter 3 year 2015
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

using namespace std;

void mystrcat( char destination[], const char source[] )
{
    int ipt1 = 0;
    
    /*if(destination[0] == '\0')
    {
        for(int i=0; source[i] != '\0'; i++)
        {
            destination[ipt1] = source[i];
            ipt1++;
        }
        destination[ipt1+1]= '\0';
        return;
    }
    */
    
    for(int i=0; true; i++)
    {
        ipt1 = i;
        if (destination[i] == '\0')
        {
            break;
        }
    }
    
    for(int i=0; true; i++)
    {
        destination[ipt1 + i ] = source[i];
        if (source[i] == '\0')
        {
            break;
        }
    }
}

int main()
{
    char arr1[25] = "";
    char arr2[25] = "";
    
    mystrcat(arr1, arr2);
    
    cout << arr1;
    
    return 0;
    
}
