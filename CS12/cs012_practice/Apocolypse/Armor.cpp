#include <iostream>
#include <string>
#include <vector>
#include "Armor.h"

using namespace std;

armor::armor()
{
    name = "Default name";
    type = "Default type";
    drop_rate = "Default drop rate";
    health = "Default health";
    armorpts = "Default armor";
    
}

armor::armor(const string& Name,const string& Type,const string& Droprate,
const string& HP, const string& AP)
{
    name = Name;
    type = Type;
    drop_rate = Droprate;
    health = HP;
    armorpts = AP;
}

bool armor::is_gun() const
{
    return false;
}

bool armor::is_melee() const
{
    return false;
}

bool armor::is_armor() const
{
    return true;
}

bool armor::is_food() const
{
    return false;
}

void armor::print_names() const
{
    cout << name << endl;
}