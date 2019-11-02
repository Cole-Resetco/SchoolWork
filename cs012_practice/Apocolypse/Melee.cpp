#include <iostream>
#include <string>
#include <vector>
#include "Melee.h"

using namespace std;

melee::melee()
{
    name = "Default name";
    type = "Default type";
    drop_rate = "Default drop rate";
    damage = "Default Damage";
    range = "Default range";
}

melee::melee(const string& Name,const string& Type,const string& Droprate,
const string& Damage, const string& Range)
{
    name = Name;
    type = Type;
    drop_rate = Droprate;
    damage = Damage;
    range = Range;
}

bool melee::is_gun() const
{
    return false;
}

bool melee::is_melee() const
{
    return true;
}

bool melee::is_armor() const
{
    return false;
}

bool melee::is_food() const
{ 
    return false;
}

void melee::print_names() const
{
    cout << name << endl;
}