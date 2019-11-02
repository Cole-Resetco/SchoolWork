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
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
 
void display(const double arr1[6][8]){
    for (int i = 1; i < 5; ++i){
        for (int j = 1; j < 7; ++j){
            cout << arr1[i][j] << ' ';
        }
        cout << endl;
    }  
}
double average(const double arr1[6][8], int i, int j){
    double sum = arr1[i + 1][j] + arr1[i - 1][j] + arr1[i][j + 1] + arr1[i][j - 1];
    return sum / 4.0;
}
int main(){
    double arr1[6][8] = {0};
    double up, down, left, right, tolerant;
    ifstream fileIn;
    string in, out;
    cout << "Please specify an imput file: ";
    cin >> in;
    cout << endl;
    cout << "Please specify an outpur file: ";
    cin >> out;
    cout << endl;
    fileIn.open(in.c_str());
    if (!fileIn.is_open()){
      cout << "Error: File could not be opened." << endl;
      return 0;
    }
    fileIn >> up;
    fileIn >> right;
    fileIn >> down;
    fileIn >> left;
    fileIn >> tolerant;
    cout << "toleranterace: " << tolerant << endl;
    for (int i = 0; i < 8; ++i){
        arr1[0][i] = up;  
    }
    for (int i = 0; i < 8; ++i){
        arr1[5][i] = down;
    }
    for (int i = 1; i < 5; ++i){
        arr1[i][0] = left;
    }
    for (int i = 1; i < 5; ++i){
        arr1[i][7] = right;
    }
    display(arr1);
    cout << endl;
    double old, newvar, margenalError = 0.0;
    do{
        for (int i = 1; i < 5; ++i){
            for (int j = 1; j < 7; ++j){
                old = arr1[i][j];
                arr1[i][j] = average(arr1, i ,j);
                newvar = arr1[i][j];
                if (i == 1 && j == 1){
                    margenalError = abs(newvar - old);
                }
                if (abs(newvar - old) > margenalError){
                    margenalError = abs(newvar - old);
                }
            }
        }
    }
    while (margenalError > tolerant);
    display(arr1);
    ofstream fileOut;
    fileOut.open(out.c_str());
    for (int i = 1; i < 5; ++i) {
            for (int j = 1; j < 7; ++j) {
                fileOut << arr1[i][j] << "\t";
            }
            fileOut << endl;
        }
    fileIn.close();
    fileOut.close();
    return 0;
}