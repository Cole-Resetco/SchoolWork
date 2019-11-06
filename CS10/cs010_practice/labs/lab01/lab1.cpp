//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab0.cpp
/// @brief Lab 0
///
/// @author Test Student [RSubEmail@ucr.edu]
/// @date April 1, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    // Ask the user for their name e.g. - Prompt the user
    
    string myName;
    
    cout << "Please enter your name" << endl;
    getline(cin, myName);
    
    
    // acquire the name from input
    // ask user how many nice days;
    
    int niceDays;
    
    cout << "hello! " << myName << " How many nice days would you prefer?" << endl;
    cin >> niceDays;
    
    // include user's responce
    //reply to user with user name and (imput number times 2)
    
    cout << myName << ", you will have " << (niceDays * 2) << " nice days!" << endl;
    
    return 0;
}