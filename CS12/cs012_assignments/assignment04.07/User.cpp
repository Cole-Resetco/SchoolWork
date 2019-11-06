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
#include "User.h"
#include <iostream>
 
using namespace std;
 
User::User()
{
    username = "";
    password = "";
}
User::User(const string& uname, const string& pass)
{
    username = uname;
    password = pass;
}
string User::get_username() const
{
    return username;
}
bool User::check(const string &uname, const string &pass) const
{
    if((username == uname && password == pass) && (uname != "" && pass != ""))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void User::set_password(const string &newpass)
{
    password = newpass;
}