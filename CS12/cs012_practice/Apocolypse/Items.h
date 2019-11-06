#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class item 
{
    protected:

        string type;
        string drop_rate;
    
    public:
        string name;
        item();
        
        item(const string& Name,const string& Type,const string& Droprate);
        
        virtual bool is_gun() const = 0;
        virtual bool is_melee() const = 0;
        virtual bool is_armor() const = 0;
        virtual bool is_food() const = 0;
        //virtual void print();
        virtual void print_names() const = 0;
};
#endif