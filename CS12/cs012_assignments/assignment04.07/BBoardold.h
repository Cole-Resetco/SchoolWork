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
#ifndef BBOARD_H
#define BBOARD_H
 
#include <iostream>
#include <vector>
#include "User.h"
#include "Message.h"
 
using namespace std;
 
class BBoard
{
    private:
        string title;
        vector<User> user_list;
        const User* current_user;
        vector<Message> message_list;
    public:
        BBoard();
        BBoard(const string &ttl);
        BBoard();
        bool load_users(const string &userfile);
        bool load_messages(const string&datafile);
        void login();
        void run();
    // private:
    //     void add_user(istream & inflie, const string &name, const string &pass);
    //     bool user_exists(const string &name, const string &pass);
    //     void display() const;
    //     void add_message();
};

#endif