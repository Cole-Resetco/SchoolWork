//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn2/main.cpp 
/// @brief Assignment/Lab 4 for CS 12 q3 2015
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date May 7 2015
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
//inclusion guards
#ifndef USER_H
#define USER_H
//includes
#include <iostream>
 
using namespace std;
 
class User
{
    private:
    string username;
    string password;
    public:
    //creates a user with empty name and password.
    User();
    // creates a user with given username and password.
    User(const string& uname, const string& pass);
    //returns the username
    string get_username() const;
    // returns true if the stored username/password matches with the
    // parameters. Otherwise returns false.
    // Note that, even though a User with empty name and password is
    // actually a valid User object (it is the default User), this
    // function must still return false if given a empty uname string.
    bool check(const string &uname, const string &pass) const;
    // sets a new password. This function will not be used in the
    // current assignment.
    void set_password(const string &newpass);
 
};
 
//end inc guards
#endif


      
      
      
      
