//  =============== BEGIN ASSESSMENT HEADER ================
/// @file madlibs.cpp
/// @brief assn1/Madlibs
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date January, 19, 2015
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>

using namespace std;

#include <iostream>
using namespace std;
int main()
{

    char insert;
    char upperBoundA = 'A';
    char upperBoundZ = 'Z';
    char lowerBounda = 'a';
    char lowerBoundz = 'z';
    char num1 = '0';
    char num2 = '9';
    cout << "Enter a character: ";
    cin >> insert;
    
    if ((insert >= 'A') && (insert <= 'Z')) {
      cout << "your entered an uppercase letter";
    }
    
    else if ((insert >= 'a') && (insert <= 'z')) {
      cout << "you entered a lowercase letter";
    } 
    
    else if ((insert >= '0') && (insert <= '9')) {
      cout << "you entered a numeric value";
    }
    else {
      cout << "you entered an unknown character type";
    }
return 0;
}