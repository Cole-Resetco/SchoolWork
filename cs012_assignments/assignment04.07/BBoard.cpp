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
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
    
using namespace std;


BBoard::BBoard()
:title("Dushan's Cancer-Curing Bulletin Board"), current_user( NULL ) {}

BBoard::BBoard( const string &ttl ):title(ttl), current_user( NULL ) {}

BBoard::~BBoard() {
    for (unsigned i = 0; i < message_list.size(); i++) {
        delete message_list.at(i);
    }
}

bool BBoard::load_users(const string& userfile) {
    string name;
    string pass;
    ifstream input;
    input.open( userfile.c_str() );
    if( input.fail() ) {
        input.close();
        return false;
    }
    while (name != "end") {
        input >> name;
        if( name != "end" ) {
            input >> pass;
            add_user( name, pass);
        }
    }
    input.close();
    return true;
}

bool BBoard::load_messages(const string& datafile) {
    string athr, sbjct, bdy, kids, thingy, input;
    unsigned id, numOfMessages;
    
    ifstream ipfile;
    ipfile.open( datafile.c_str() );
    
    if (ipfile.fail()) {
        return false;
    }
    ipfile >> numOfMessages; 
    vector< vector<int> > temp_kids(numOfMessages + 10);
    while (numOfMessages != 0) {
        ipfile >> thingy;
        input = ""; 
        id = 0;
        sbjct = "";
        athr = "";
        bdy = "";
        kids = "";
        while (input != "<end>") {
            ipfile >> input; 
            if (input == ":id:") {
                ipfile >> id;
            } else if (input == ":subject:") {
                getline( ipfile, sbjct );
                cout << "Sbjct: " << sbjct << endl;
                sbjct = sbjct.substr(1);
                cout << "New sbjct: " << sbjct << endl;
            } else if (input == ":from:") {
                ipfile >> athr;
            } else if (input == ":children:") {
                getline( ipfile, kids);
                kids = kids.substr(1);
                
                
                int temp;
                stringstream iss( kids );
                while (iss >> temp) {
                    cout <<"Temp: " << temp << endl;
                    cout <<"Id: " << id << endl;
                    temp_kids.at(id-1).push_back(temp);
                }
                
                // for(unsigned i = 0; i < temp_kids.size(); i++)
                // {
                //     cout << endl;
                //     for(unsigned j = 0; j < temp_kids.at(i).size(); j++)
                //     {
                //         cout << ' ' << temp_kids.at(i).at(j) << ' ';
                //     }
                // }
            } else if (input == ":body:") {
                while (input != "<end>") {
                    getline( ipfile, input );
                    if (input == "<end>") {
                        
                        break;
                    }
                    bdy = bdy + input + '\n'; 
                }
                bdy = bdy.substr(1);
                bdy = bdy.substr(0, bdy.size()-1);
            }
        } 
        if (thingy == "<begin_topic>") {
            message_list.push_back( new Topic(athr, sbjct, bdy, id) );
        } else if( thingy == "<begin_reply>" ) {
            message_list.push_back( new Reply(athr, sbjct, bdy, id) );
        }
        numOfMessages--;
    }
    ipfile.close();
    for (unsigned i = 0; i < message_list.size(); i++) {
        
        for (unsigned j = 0; j < temp_kids.at(i).size(); j++) {
            message_list.at(i) -> 
            add_child( message_list.at( temp_kids.at(i).at(j) - 1 ) );
            
        }
    }
    return true;
}

bool BBoard::save_messages(const string& datafile) {
    ofstream opfile;
    opfile.open( datafile.c_str() );
    if (opfile.fail()) {
        return false;
    }
    opfile << message_list.size() << endl;
    for (unsigned i = 0; i < message_list.size(); i++) {
        opfile << message_list.at(i) -> to_formatted_string();
    }
    opfile.close();
    return true;
}

void BBoard::login() {  
    string name, pass;
    cout << "Welcome to " << title << endl;
    while ( get_user(name,pass) == NULL ) {
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> name;
        if (name == "Q" || name == "q") {
            cout << "Bye!" << endl;
            return;
        } else {
            cout << "Enter your password: ";
            cin >> pass;
            if (get_user(name,pass) == NULL) {
                cout << "Invalid Username or Password!" << endl << endl;
            } else {
                cout << "Welcome back " << name << "!" << endl << endl;
                current_user = get_user(name,pass);
            }
        }
    }
}

void BBoard::run() {
    char input;
    if (current_user == NULL) {
        return;
    }
    do {
        cout << "Menu" << endl;
        cout << "  " << "- Display Messages ('D' or 'd')" << endl
             << "  " << "- Add New Topic ('N' or 'n')" << endl
             << "  " << "- Add Reply ('R' or 'r')" << endl
             << "  " << "- Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> input;
        cout << endl;
        if (input == 'D' || input == 'd') {
            display();
        } else if( input == 'N' || input == 'n' ) {
            add_topic();
        } else if( input == 'R' || input == 'r' ) {
            add_reply();
        } else if( input == 'Q' || input == 'q' ) {
            cout << "Bye!" << endl;
            return;
        } else { 
            cout << "Invalid action. Please try again." << endl << endl;
        }
    } while( input != 'Q' || input != 'q' );
}
   
void BBoard::add_user(const string& name, const string& pass) {
    user_list.push_back( User(name,pass) );
}

const User* BBoard::get_user(const string& name, const string& pw) const {
    for (unsigned i = 0; i < user_list.size(); i++) {
        if ( user_list.at(i).check(name, pw) ) {
            return &user_list.at(i);
        }
    }
    return NULL;
}

void BBoard::display() const {
    if (message_list.size() == 0) {
        cout << "Nothing to Display." << endl << endl;
    } else {
        for (unsigned i = 0; i < message_list.size(); i++) {
            if ( !(message_list.at(i) -> is_reply()) ) {
                cout << "-----------------------------------------------";
                message_list.at(i) -> print(0);
            }
        }
        cout << "-----------------------------------------------" << endl;
    }
    
}

void BBoard::add_topic() {
    string author = current_user -> get_username();
    string subject; 
    string body, temp = " ";
    int id = message_list.size() + 1;
    cin.ignore(1000, '\n'); 
    cout << "Enter Subject: ";
    getline( cin, subject );
    cout << "Enter Body: ";
    while( temp != "" ) {
        getline( cin, temp );
        if( temp == "" ) {
            break;
        }
        body = body + temp + '\n';
    }
    body = body.substr(0, body.size()-1);
    Topic* temp_topic = new Topic( author, subject, body, id );
    message_list.push_back( temp_topic );
}
    
void BBoard::add_reply() {
    string author = current_user -> get_username();
    string subject; 
    string body, temp = " ";
    int message_id;
    int id = message_list.size() + 1; 
    while( true ) {
        cout << "Enter Message ID (-1 for Menu): ";
        cin >> message_id;
        if (message_id == -1) {
            return;
        } else if( message_id == 0 || message_id > 
                   static_cast<int>(message_list.size()) ) {
            cout << "Invalid Message ID!!" << endl << endl;
        } else {
            break;
        }
    }
    subject = "Re: " + message_list.at( message_id - 1 ) -> get_subject();
    cout << "Enter Body: ";
    cin.ignore(1000, '\n'); 
    while( temp != "" ) {
        getline( cin, temp );
        if( temp == "" ) {
            break;
        }
        body = body + temp + '\n'; 
    }
    body = body.substr(0, body.size()-1);
    
    Reply* reply_temp = new Reply(author, subject, body, id);
    message_list.push_back( reply_temp ); 
    message_list.at(message_id - 1) -> add_child( reply_temp );
}