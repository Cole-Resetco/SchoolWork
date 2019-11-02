#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "Interface.h"

using namespace std;

Interface::Interface()
{
    title = "Default Apocolypse";
}

Interface::Interface(const string &ttl)
{
    title = ttl;
}

void Interface::import_items(const string& datafile)
{
    string item_type;
    string type;
    string name;
    string armorpts;
    string healthpoints;
    string range;
    string damage;
    string droprate;
    string regen;
    string caliber;
    string input;
    string description;
    
    
    ifstream inf; //creates a "command" for importing data
    inf.open( datafile.c_str() ); // opens up the "datafile" 
    
     if(!inf.is_open())
    {
        cout << "Error: Cannot open message list file" << endl;
        exit(0);
        
        // checks for if the file opened correctly
    }
    
    //cout << "Datafile opened" << endl;
    
    while(!(input == "Finished")) // loop while it doesnt read in "Finished"
    {
        inf >> item_type; //reads in <item_type> as first inf
        
        type = "";
        name = "";
        armorpts = "";
        healthpoints = ""; // sets all strings to nothing as a reset each loop
        range = "";
        damage = "";
        droprate = "";
        regen = "";
        caliber = "";
        input = "";
        description = "";
        
        while (input != "<End_item>") // will continue readin in infs until it reads in <End_item>
        {
            inf >> input; // reads  the next inf
            //cout << "The input is: "<< input << endl; //checking the input
            if(input == "Finished")
            {
                break;
            }
            else if(input == ":Type:") {  // if input finds "Type" identifier
                getline(inf, type);
                //cout << "Type:          " << type <<endl;
            }
            else if(input == ":Drop_Rate:") // cheching for drop rate identifer
            {
                getline(inf, droprate);
                //cout << "Drop rate:     " << droprate <<endl;
            }
            else if(input == ":Name:") // checking for name identifier
            {
                getline(inf, name);
                //cout << "Name:          " << name << endl;
            }
            else if(input == ":HP:") // cheching for HP identifer
            {
                getline(inf, healthpoints);
                //cout << "HP:            " << healthpoints <<endl;
            }
            else if(input == ":AP:") // cheching for AP identifer
            {
                getline(inf, armorpts);
                //cout << "AP:            " << armorpts <<endl;
            }
            else if(input == ":Range:") // cheching for range identifer
            {
                getline(inf, range);
                //cout << "Range:         " << range <<endl;
            }
            else if(input == ":Damage:") // cheching for damage identifer
            {
                getline(inf, damage);
                //cout << "Damage:        " << damage <<endl;
            }
            else if(input == ":Caliber:") // cheching for caliber identifer
            {
                getline(inf, caliber);
               // cout << "Caliber:       " << caliber <<endl;
            }
            else if(input == ":HP_Regen:") // cheching for regen identifer
            {
                getline(inf, regen);
                //cout << "Regen:         " << regen <<endl;
            }
        }
        
        //cout << "End item --------------------------------------------" << endl;
        if(item_type == "<New_gun>")
        {
            Item_list.push_back( new guns(name, type, droprate, caliber, damage,
                                          range));
            cout << "Found gun" << endl;
        }
        
        else if(item_type == "<New_melee>")
        {
            Item_list.push_back(new melee(name, type, droprate, damage, range));
            cout << "Found melee" << endl;
        }
        
        else if(item_type == "<New_armor>")
        {
            Item_list.push_back(new armor(name, type, droprate, healthpoints, 
            armorpts));
            cout << "Found armor" << endl;
        }
        
        else if(item_type == "<New_food>")
        {
            Item_list.push_back(new food(name, type, droprate, regen));
            cout << "Found food" << endl;
        }
        //cout << "End found -------------------------------------------" << endl;
    }
        
        
}

void Interface::begin_interface()
{
    string user_Input;
    int check_Flag = 0;
    cout << endl;
    cout << "Welcome to the apocolypse random item archiver!!!";
    
    cout << endl;
    cout << endl;
    
    cout << "Before we begin, I would like to state that all items listed " <<
            "are possibly real or fictional. Furthermore all items have " << 
            "the ability to be changed and items can be added. So all " <<
            "information on the given items is not to be taken as true" <<
            endl;
    
    cout << endl;
    cout << "To begin, Type ''Begin'' or ''Quit'' to quit " << endl;
    
    while(check_Flag == 0)
    {
        
    
        cin >> user_Input; 
        
        if(user_Input == "Begin")
        {
            check_Flag = 1;
        }
        else if(user_Input == "Quit")
        {
            cout << "Exiting program" << endl;
            exit(0);
        }
        else 
        {
            cout << "..." << endl;
        }
    
    }
    
}
void Interface::list_items()
{
    cout << "Here are the current items we have archived" << endl;
    cout << "------------------------------------------ " << endl;
    cout << endl;
    
    for(unsigned i = 0; i < Item_list.size(); i++)
    {
        Item_list.at(i)-> print_names();
    }
}