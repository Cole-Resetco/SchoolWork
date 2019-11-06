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
#include "BBoard.h"
#include <fstream>
#include <cstdlib>
 
using namespace std;
 
//public
BBoard::BBoard()
{
    title = "Default";
    current_user = 0;

    
}
 
BBoard::BBoard(const string &ttl)
{
    title = ttl;
    current_user = 0;
    message_list;
    user_list;
}

// BBoard::~BBoard()
// {
//     delete[]message_list;
//     message_list = 0;
// }
bool BBoard::load_users(const string &userfile)
{
    ifstream user_names;
    user_names.open(userfile.c_str());
   
    string username;
    string password;
    if(!user_names.is_open())
    {
        cout << "Error: Cannot open input file" << endl;
        return false;
    }
   
    while(username != "end")
    {
        user_names >> username;
        user_names >> password;
        User newUser(username, password);
        user_list.push_back(newUser);
    }
    user_names.close();
    return true;
}

bool BBoard::load_messages(const string& datafile)
{
    ifstream messages;
    messages.open(datafile.c_str());
    
    if(!messages.is_open())
    {
        cout << "Error: Cannot open message list file" << endl;
        return false;
    }
    
    return true;
    
}

void BBoard::login()
{
    string user;
    string pass;
    int check = 0;
   
    cout << "Welcome to Cole's Amazing Bulleting Board" << endl;
    while(check == 0)
    {
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> user;
        if(user == "Q" || user == "q")
        {
            cout << "Bye!" << endl;
            exit(0);
        }
        cout << "Enter your password: ";
        cin >> pass;
        current_user = &user_list.front();
        for(unsigned i = 0; i < user_list.size(); ++i) 
        {
            if(user_list.at(i).check(user, pass) == false)
                current_user++;
            else
            {
                check = 1;
                break;
            }
        }
        if(check == 0)
        {
            cout << "Invalid Username or Password!" << endl;
        }
    }
    cout << "Welcome back " << current_user->get_username();
}
void BBoard::run()
{
    cin.ignore();
    if(current_user->get_username() == "")
    {
        exit(0);
    }
   
    string user_in;
    string subject;
    string body;
    unsigned strtid = 0;
   
    while(user_in != "Q" || user_in != "q")
    {
        cout << endl << "Menu" << endl;
        cout << "  - Display Messages ('D' or 'd')" << endl << "  - Add New Message ('N' or 'n')" << endl
            << "  - Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        getline(cin, user_in);
        if(user_in == "Q" || user_in == "q")
        {
            cout << "Bye!" << endl;
            exit(0);
        }
        if(user_in == "D" || user_in == "d")
        {
            if(message_list.empty())
            {
                cout << "Nothing to Display." << endl;
            }
            else
            {
                cout << "-----------------------------------------------" << endl;
                for(unsigned i = 0; i < message_list.size(); ++i)
                {
                    cout << "Message #" << i + 1 << ": ";
                    message_list.at(i).display();
                    cout << "-----------------------------------------------" << endl;
                }
            }
        }
        else if(user_in == "N" || user_in == "n")
        {
            cout << "Enter subject: ";
            getline(cin, subject);
            cout << "Enter Body: ";
            getline(cin, body);
            strtid++;
            Message topic(current_user->get_username(), subject, body, strtid);
            message_list.push_back(message);
        }
    }
}


//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn4/BBoard.cpp 
/// @brief Assignment 4 for CS 12 quarter 2, 2015
///
/// @author Akshay Chikmagalur [achik002@ucr.edu]
/// @date February 13, 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 024
/// @par
///     TA: D Tao
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
    
using namespace std;    

//begin constructors
Bboard::Bboard()
:title("Akshay's Bulletin Board"), current_user( 0 ) {
            //default constructor
}

Bboard::Bboard( const string &ttl )     
:title(ttl), current_user(0) {
    
}

Bboard::~Bboard() {
    for (unsigned i = 0; i < message_list.size(); i++) {
        delete message_list.at(i);
    }
     
}
//end constructors


bool Bboard::load_users(const string& userfile) {  //setup function
    string name;    //input for username
    string pass;    //input for password
    
    ifstream fin;
    fin.open( userfile.c_str() );
    
    if( fin.fail() ) {
        fin.close();
        return false;
    }
        while (name != "end") {  
            
            fin >> name;        
            
            if( name != "end" ) {
                fin >> pass;
                add_user( name, pass);  
            }
            
        }
        
        fin.close();
        return true;
}


void Bboard::login() 
{    
    
    string n;
    string p;  
    
    cout << "Welcome to " << title << endl;  
    
    while ( get_user(n,p) == 0 ) {
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> n;    
        
        if (n == "Q" || n == "q") {   
            cout << "Bye!" << endl;
            exit(0);
        } else {      
            cout << "Enter your password: ";
            cin >> p;
            
            if (get_user(n,p) == 0) { 
                cout << "Invalid Username or Password!" << endl << endl;
            } else {    
                cout << "Welcome back " << n << "!" << endl << endl;
                current_user = get_user(n,p);
            }
        }
        
    }
    
}


void Bboard::run() {    //run function
    
    char in; //input variable
    
    if (current_user == 0) {
        exit(1);
    }
    
    do {
        
        cout << "Menu" << endl; //display the entire menu
        cout << "  " << "- Display Messages ('D' or 'd')" << endl
             << "  " << "- Add New Topic ('N' or 'n')" << endl
             << "  " << "- Add Reply ('R' or 'r')" << endl
             << "  " << "- Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> in;   //takes in input
        
        cout << endl;
        
        if (in == 'D' || in == 'd') { //if D or d, display the bulletin
            display();
        } else if( in == 'N' || in == 'n' ) { //writes a new bulletin
            add_topic();
        } else if( in == 'R' || in == 'r' ) {
            add_reply();
        } else if( in == 'Q' || in == 'q' ) { //quits the program
            cout << "Bye!" << endl;
            return;
        } else {    //tells user that the input is invalid
            cout << "Invalid action. Please try again." << endl << endl;
        }
        
        
        
    } while( in != 'Q' || in != 'q' );    //breaks when in is Q or q
    
}


bool Bboard::load_messages(const string& datafile) {
    string athr;
    string sbjct;
    string bdy;
    string children;
    string tpicRply;
    string input;
    unsigned id, numOfMessages; 
    
    ifstream fin;
    fin.open( datafile.c_str() );    //open datafile
    
    if (fin.fail()) {
        return 0; //return false   
    }
    
    fin >> numOfMessages;    
    vector< vector<int> > temp_children(numOfMessages);
    
    while (numOfMessages != 0) {    
        fin >> tpicRply;   
        
        input = ""; 
        id = 0;
        sbjct = "";
        athr = "";
        bdy = "";
        children = "";
        
        while (input != "<end>") {  
            
            fin >> input;    
            
            if (input == ":id:") {  
                fin >> id;
            } else if (input == ":subject:") {  
                getline( fin, sbjct );
                sbjct = sbjct.substr(1);
            } else if (input == ":from:") { 
                fin >> athr;
            } else if (input == ":children:") { 
                getline( fin, children);
                children = children.substr(1);  //stating from pos 1
                
                int temp;
                
                stringstream iss( children );
                while (iss >> temp) {       
                    temp_children.at(id-1).push_back(temp);
                }
                
            } else if (input == ":body:") {
                while (input != "<end>") {
                    
                    getline(fin, input);  
                    
                    if (input == "<end>") {
                        break;  
                    }
                    
                    bdy = bdy + input + '\n';   
                }
                
                bdy = bdy.substr(1);    
                bdy = bdy.substr(0, bdy.size()-1);
            }
            
        }
            
        if (tpicRply == "<begin_topic>") {
            message_list.push_back( new Topic(athr, sbjct, bdy, id) );
        } else if( tpicRply == "<begin_reply>" ) {
            message_list.push_back( new Reply(athr, sbjct, bdy, id) );
        }
        
        numOfMessages--;
    }
    
    fin.close();//close the input file
    
    unsigned i = 0;
    while (i < message_list.size())
    {
        for (unsigned j = 0; j < temp_children.at(i).size(); j++) {
            message_list.at(i) ->   //assigns all the pointers to chidren
            add_child( message_list.at( temp_children.at(i).at(j) - 1 ) );
        }
        i++;
    }
    
    return 1;
}


void Bboard::add_topic() 
{  
    string athr = current_user -> get_username();
    string sbjct; //initialize variables
    string body, temp = " ";
    int id = message_list.size() + 1;   
    
    cin.ignore(1000, '\n'); 
    
    cout << "Enter Subject: "; 
    getline( cin, sbjct );
    
    cout << "Enter Body: "; 
    
    while( temp != "" ) {
        getline( cin, temp );
                
        if( temp == "" ) {
            break;
        }
        
        body = body + temp + '\n';  
    }
    
    body = body.substr(0, body.size()-1);   
    Topic* temp_topic = new Topic( athr, sbjct, body, id );
    message_list.push_back( temp_topic );   
    }
void Bboard::display() const {  
    
    if (message_list.size() == 0) { 
        cout << "Nothing to Display." << endl << endl;
    } else {
        for (unsigned i = 0; i < message_list.size(); i++) {
            
            if ( !(message_list.at(i) -> is_reply()) ) {
                cout << "-----------------------------------------------"
                     << endl;
                message_list.at(i) -> print(); //uses message display function
            }
            
        }
        
        cout << "--------------- --------------------------------" << endl;
    }
    
}  

void Bboard::add_reply() {  
    string author = current_user -> get_username();
    string sbjct; 
    string bdy, temp = " ";
    int message_id;
    int id = message_list.size() + 1;   
    
    while(true) {
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
    
    sbjct = "Re: " + message_list.at(message_id - 1) -> get_subject();
    cout << "Enter Body: ";
    
    cin.ignore(1000, '\n'); 
    
    while( temp != "" ) {
        getline( cin, temp );   
        
        if( temp == "" ) {  
            break;
        }
        
        bdy = bdy + temp + '\n';  
    }
    
    bdy = bdy.substr(0, bdy.size()-1);   
    
    Reply* reply_temp = new Reply(author, sbjct, bdy, id);
    message_list.push_back( reply_temp );   
        
    message_list.at(message_id - 1) -> add_child( reply_temp );
}
   
   
void Bboard::add_user( const string &name, const string &pass ) {
    user_list.push_back( User(name,pass) );
}

bool Bboard::save_messages(const string& datafile) {
    ofstream out;    
    out.open( datafile.c_str() );
    
    if (out.fail()) {    
        return 0;
    }
    
    out << message_list.size() << endl;  
    unsigned i = 0;
    while (i < message_list.size())
    {
        out << message_list.at(i) -> to_formatted_string();
        i++;
    }
    
    out.close(); 
    return 1;    
}

const User* Bboard::get_user(const string& name, const string& pw) const {
    unsigned i = 0;
    while(i < user_list.size())
    {
        if ( user_list.at(i).check(name, pw) ) {
            return &user_list.at(i); 
        }
        i++;
    }
    
    return 0;
}
