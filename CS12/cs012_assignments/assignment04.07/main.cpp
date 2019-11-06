//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn2/main.cpp 
/// @brief Assignment/Lab 7 for CS 12 q3 2015
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date June 4 2015
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
#include "BBoard.h"
#include "Reply.h"
#include "Topic.h"
#include "Message.h"
#include "User.h"
#include <iostream>
 
using namespace std;
 
//includes

int main(int argc, char **argv)
{
    // check commandline arguments 
    // (see Zyante Chapter 8, section 8.7 for explanations and examples)   
    if (argc != 3){
        cout << "ERROR: Invalid program call." << endl
            << "Usage: <program_name> userfile datafile" << endl;
        return 1;
    }
    string userfile(argv[1]);
    string datafile(argv[2]);
    
   
    BBoard bb("CS12 Bulletin Board");
    
   
    // load users from file
    if (!bb.load_users(userfile))
    {
        cout << "ERROR: Cannot load users from " << userfile << endl;
        return 1;
    }
   
    // load messages   
    if (!bb.load_messages(datafile))
    {
        cout << "ERROR: Cannot load messages from " << datafile << endl;
        return 1;
    }
    bb.login();
    
    cout << "Finished" << endl;
    
    bb.run();

    // save messages
    
    cout << "Saving..." << endl;
    
    if (!bb.save_messages(datafile))
    {
        cout << "ERROR: Cannot save messages to " << datafile << endl;
        return 1;
    }
    
    cout << "Saved" << endl;

    return 0;
} 

