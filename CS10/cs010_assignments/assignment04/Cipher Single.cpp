//  =============== BEGIN ASSESSMENT HEADER ================
/// @file isbn.cpp
/// @brief Assignment 3
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date February 1, 2015
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
 
using namespace std;
 
int main()
{
    string defaultString = "zyxwvutsrqponmlkjihgfedcba";
    string userMap; //creates the user map
    string mapOne;
    string word;
    char letter;
    int letterNum;
   
    cout << "What is the translation map (type 'default' to use default): ";
    cin >> mapOne;
    if (mapOne != "default")
    {
        userMap = mapOne;
    } else
    {
        userMap = defaultString;
    }
   
    if (userMap.size() != 26)
    {
        cout << "\nError: invalid translation map size.";
        return 0;
    }
   
    cout << "\nWhat is the single word to translate: ";
    cin >> word;
    letter = word.at(0);
    if ((letter >= 'a') && letter <= 'z')
    {
        letterNum = letter - 97;
    } else
    {
        cout << "\nError: encryption cannot be performed.";
        return 0;
    }
    word.at(0) = userMap.at(letterNum);
    cout << "\nEncrypted word: " << word << endl;
   
    return 0;
}