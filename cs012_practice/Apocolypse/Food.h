#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include <vector>
#include "Items.h"

using namespace std;

class food : public item
{
    private:
        string HP_regain;
    
    public:
        food();
        
        food(const string& Name,const string& Type,const string& Droprate,
             const string& HP);
        virtual bool is_gun() const;
        virtual bool is_melee() const;
        virtual bool is_armor() const;
        virtual bool is_food() const;
        //void print();
        virtual void print_names() const;
};
#endif