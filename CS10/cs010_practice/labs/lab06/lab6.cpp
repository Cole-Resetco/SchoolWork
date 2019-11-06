//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab04.cpp
/// @brief lab4/Branches and Chars
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date January, 29, 2015
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>

using namespace std;

int main()
{

    int countA = 0;
    int countB = 0;
    int countC = 0;
    int countD = 0;
    int countF = 0;
    int inputGrade;
    cout << "Enter one or more grades, or -1 to stop:" << endl;

    do {
        cin >> inputGrade;
        
        if ((inputGrade >=0) && (inputGrade <= 59)) {
            ++ countF; // adds 1 to F if grade is between 
        }
        
        if ((inputGrade >=60) && (inputGrade <= 69)) {
            ++ countD; // adds 1 to D if grade is between 
        }
        
        if ((inputGrade >=70) && (inputGrade <= 79)) {
            ++ countC; // adds 1 to C if grade is between 
        }
        
        if ((inputGrade >=80) && (inputGrade <= 89)) {
            ++ countB; // adds 1 to B if grade is between 
        }
        
        if ((inputGrade >=90) && (inputGrade <= 100)) {
            ++ countA; // adds 1 to A if grade is between 
        }
     
    } while (inputGrade != -1);

    cout << endl;

    cout << "The grades breakdown is:" << endl; 


    cout << "As: " << countA << endl;
    cout << "Bs: " << countB << endl;
    cout << "Cs: " << countC << endl;
    cout << "Ds: " << countD << endl;
    cout << "Fs: " << countF << endl;


    return 0;
}