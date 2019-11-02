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

#include "Reply.h"
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

Reply::Reply():Message() {}

Reply::Reply(const string& athr, const string& sbjct,
      const string& body, unsigned id):Message(athr, sbjct, body, id) {}

string Reply::to_formatted_string() const {
    string topic_formatted;
    topic_formatted = "<begin_reply>\n:id: " + intToString(id) + "\n:subject: "
    + subject + "\n:from: " + author;
    
    if (child_list.size() != 0) {
        topic_formatted += "\n:children: ";
        for (unsigned i = 0; i < child_list.size(); i++) {
            topic_formatted = topic_formatted
            + intToString( child_list.at(i) -> get_id() ) + ' ';
        }
    }
    topic_formatted = topic_formatted + '\n' +":body: " + body + '\n' +
    "<end>" + '\n';
    return topic_formatted;
    
}

bool Reply::is_reply() const {
    return true;
}

string Reply::intToString(const unsigned& number) const {
    stringstream ss;
    ss << number;
    return ss.str();
}



