#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
#include <string>
#include <vector>
#include "Items.h"

using namespace std;

class armor : public item
{
    private:
        string health;
        string armorpts;
    
    public:
        armor(); //default constructor
        
        armor(const string& Name, const string& Type, const string& Droprate,
             const string& HP, const string& AP); //parametarize constructor
        
        virtual bool is_gun() const;
        virtual bool is_melee() const;
        virtual bool is_armor() const;
        virtual bool is_food() const;
        //void print();
        virtual void print_names() const;
};
#endif