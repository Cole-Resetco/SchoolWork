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

#ifndef BBoard_H //inclusion guard
#define BBoard_H

#include "User.h"   //include user.h
#include "Topic.h"
#include "Reply.h"
#include "Message.h"

#include <iostream>//iostream and vector
#include <vector>

using namespace std;    //standard namespace

class BBoard {  //BBoard class
    
private:
    string title;   //title of BBoard
    vector<User> user_list; //vector of users
    const User* current_user;  //current user logged in
    vector<Message*> message_list;   //message list vector
    
public:
    BBoard();   //defauly constructor
    BBoard( const string &ttl );    //constructor
    ~BBoard();
    bool load_users(const string& userfile);   //setup function
    void login();   //login function
    void run();     //run function
    bool load_messages(const string& datafile); //gets all messages, datafile
    bool save_messages(const string& datafile); //prints all messages, datafile
    void add_topic();   //adds topic to messagelist
    void add_reply();   //adds reply to messagelist
    
private:    
    void add_user(const string& name, const string& pass);
        //adds user to the user_list vector
    const User* get_user(const string& name, const string& pw) const;
        //gets a user with the name
    void display() const;
        //displays the format for the messages
    
};

#endif //__BBoard_H_
