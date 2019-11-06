#include <iostream>
#include <string>
#include <vector>
#include "Guns.h"

using namespace std;

guns::guns()
{
    name = "Default name";
    type = "Default type";
    drop_rate = "Default drop rate";
    caliber = "Default Caliber";
    damage = "Default Damage";
    range = "Default range";
}

guns::guns(const string& Name,const string& Type,const string& Droprate,
const string& Caliber, const string& Damage, const string& Range)
{
    name = Name;
    type = Type;
    drop_rate = Droprate;
    caliber = Caliber;
    damage = Damage;
    range = Range;
}

bool guns::is_gun() const
{
    return true;
}

bool guns::is_melee() const
{
    return false;
}

bool guns::is_armor() const
{
    return false;
}

bool guns::is_food() const
{
    return false;
}

void guns::print_names() const
{
    cout << name << endl;
}