#include <iostream>
#include <string>
#include <vector>
#include "Items.h"

using namespace std;

item::item()
{
    name = "Default name";
    type = "Default type";
    drop_rate = "Default drop rate";
    
}

item::item(const string& Name,const string& Type,const string& Droprate)
{
    name = Name;
    type = Type;
    drop_rate = Droprate;
    
}

bool item::is_gun() const
{
    return false;
}

bool item::is_melee() const
{
    return false;
}

bool item::is_armor() const
{
    return false;
}

bool item::is_food() const
{
    return false;
}