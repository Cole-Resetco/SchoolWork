//  =============== BEGIN ASSESSMENT HEADER ================
/// @file isbn.cpp
/// @brief Assignment 2
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date January 25, 2015
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
 
using namespace std;
 
int main()
{
    int ISBN;
    int checkSum;
    
    int a, b, c, d, e, f, g, h, i; // creates ints a b c d e f g h i
    
    cout << "Please enter the first 9 digits of the ISBN: ";
    cin >> ISBN;
    
    //hey this is a comment. fuck u rsub
    //isbn = 987654321
    
    a = ISBN / 100000000;
    b = (ISBN / 10000000) % 10;
    c = (ISBN / 1000000) % 10;
    d = (ISBN / 100000) % 10;
    e = (ISBN / 10000) % 10;
    f = (ISBN / 1000) % 10;
    g = (ISBN / 100) % 10;
    h = (ISBN / 10) % 10;
    i = (ISBN / 1) % 10;
    
    checkSum = ((a * 1) + (b * 2) + (c * 3) + (d * 4) + (e * 5) + (f * 6)
    + (g * 7) + (h * 8) + (i * 9)) % 11; 
    cout << endl;
    cout << "Checksum: " << checkSum;
    
    return 0;
}