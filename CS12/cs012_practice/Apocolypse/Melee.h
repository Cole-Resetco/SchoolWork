#ifndef MELEE_H
#define MELEE_H

#include <iostream>
#include <string>
#include <vector>
#include "Items.h"

using namespace std;

class melee : public item
{
    protected:
        string damage;
        string range;
    
    public:
        melee();
        
        melee(const string& Name,const string& Type,const string& Droprate,
              const string& Damage, const string& Range);
              
        virtual bool is_gun() const;
        virtual bool is_melee() const;
        virtual bool is_armor() const;
        virtual bool is_food() const;
        //void print();
        virtual void print_names() const;
};
#endif