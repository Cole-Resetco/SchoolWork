#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <vector>
#include "Items.h"
#include "Guns.h"
#include "Melee.h"
#include "Armor.h"
#include "Food.h"

using namespace std;

class Interface 
{
    private:
        string title;
        vector<item*> Item_list;

    
    public: 
        Interface();                                 //works
        Interface(const string &ttl);                //works
        void change_name();
        void import_items(const string &datafile);   //works
        void save_items();
        void begin_interface();                        //working
        void list_items();
        
};
#endif