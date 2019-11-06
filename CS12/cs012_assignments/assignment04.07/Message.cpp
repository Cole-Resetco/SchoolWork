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

#include "Message.h"
#include "Reply.h"
#include "Topic.h"
#include <iostream>
#include <vector>
using namespace std;

Message::Message():author(""), subject(""), body(""){}

Message::Message(const string& athr, const string& sbjct, const string& body, unsigned id)
:author(athr), subject(sbjct), body(body), id(id){}

Message::~Message(){
    for(unsigned i = 0; i < child_list.size(); i++)
        delete child_list.at(i);
}

/*void Message::print(unsigned indentation) const{
    string indent(indentation,'\t');
    cout << "Message #" << id << ": " << subject << endl;
    cout << "from " << author << ": " << body << endl;
}
*/
void Message::print(unsigned indentation) const {
    cout << endl;
    for (unsigned j = 0; j < indentation; j++) {
        cout << "  ";
    }
    cout << "Message #" << id << ": " << subject << endl;
    for (unsigned j = 0; j < indentation; j++) {
        cout << "  ";
    }
    cout << "from " << author << ": ";
    for (unsigned j = 0; j < body.size(); j++) {
        cout << body.at(j);
        if (body.at(j) == '\n') {
            for (unsigned k = 0; k < indentation; k++) {
                cout << "  ";
            }
        }
    }
    cout << endl;
    for (unsigned i = 0; i < child_list.size(); i++) {
        ( child_list.at(i) ) -> print(indentation + 1);
    }
}

bool Message::is_reply() const {
    return false;
}

const string& Message::get_subject() const {
    return subject;
}

unsigned Message::get_id() const {
    return id;
}

void Message::add_child(Message* child) {
    child_list.push_back(child);
}