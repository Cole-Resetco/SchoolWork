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

#ifndef REPLY_H
#define REPLY_H
#include <iostream>
#include "Message.h"
using namespace std;

  class Reply:public Message{
   // no new member variables

   public:
     //default constructor
     Reply();

     /* Parameterized constructor - similar to Message's constructor except:
      * The subject should be initialized to "Re: <sbjct>" not <sbjct>.
      */
     Reply(const string &athr, 
           const string &sbjct, 
           const string &body, 
           unsigned id);
     
     virtual bool is_reply() const; // Returns true
     
     /* to_formatted_string writes the contents of the Reply to a string in the 
      * following format:
        
       <begin_reply>
       :id: 4
       :subject: single line
       :from: author
       :children: 5 6 [this line should not be printed if there are no children.]
       :body: multiple lines
       2nd line
       <end>

      * the line starting with :children: has the list of id's of all children 
      * (See file specs. for details)
      * This function should not assume the last character in body is a newline.
      * In other words, this function must manually add a newline after the last line
      * of the body (line 3 in this example).
      * Also, the last character in the string must be a newline.
      */
     virtual string to_formatted_string() const; // New !!
      
    private:
        string intToString(const unsigned& number) const;
  };
#endif