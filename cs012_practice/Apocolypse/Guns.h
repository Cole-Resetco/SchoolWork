#ifndef GUNS_H
#define GUNS_H

#include <iostream>
#include <string>
#include <vector>
#include "Items.h"

using namespace std;

class guns:public item{
    private:
        string caliber;
        string damage;
        string range;
    
    public:
        guns(); //default constructor
        
        guns(const string& Name, const string& Type, const string& Droprate,
             const string& Caliber, const string& Damage, const string& Range); //parametarize constructor
        
        virtual bool is_gun() const;
        virtual bool is_melee() const;
        virtual bool is_armor() const;
        virtual bool is_food() const;
        //void print();
        virtual void print_names() const;
};
#endif