//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#>/main.cpp 
/// @brief Assignment/Lab 6 for CS 12 <spring 2015>
///
/// @author <Cole Resetco> [crese002@ucr.edu]
/// @date <5/21/2015>
///
/// @par Enrollment Notes 
///     Lecture Section: <001>
/// @par
///     Lab Section: <e.g. 021>
/// @par
///     TA: <lab guy>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============


#include <iostream>
#include <cstdlib>
#include "IntList.h"

using namespace std;

void reverse (string &s)
{
    
    if(s.size() == 0)
    {
        return;
    }
    else
    {
        //cout << "starting recurstion" << endl;
        //cout << "this is the string: " << s << ", this is the size: " << s.size() << endl;
        cout << s.at(s.size() - 1);
        s = s.substr(0, s.size() - 1);
        reverse(s);

        return;
    }
    return;
    
}

int main()
{
    return 0;
}