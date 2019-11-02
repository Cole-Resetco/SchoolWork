//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn2/main.cpp 
/// @brief Assignment/Lab 2 for CS 12 q3 2015
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date April 16 2015
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
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Date
{
    private:
        unsigned day;
        unsigned month;
        string monthName;
        unsigned year;
        bool isLeap(unsigned) const;
        unsigned daysPerMonth(unsigned, unsigned) const;
        string name(unsigned) const;
        unsigned number(const string &) const;
    public:
        Date();
        Date(unsigned, unsigned, unsigned);
        Date(const string &, unsigned, unsigned);
        void printNumeric() const;
        void printAlpha() const;
};