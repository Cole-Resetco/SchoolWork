#include <iostream>
#include <string>
#include <vector>
#include "Food.h"

using namespace std;

food::food()
{
    name = "Default name";
    type = "Default type";
    drop_rate = "Default drop rate";
    HP_regain = "Default regain";

}

food::food(const string& Name,const string& Type,const string& Droprate,
const string& HP)
{
    name = Name;
    type = Type;
    drop_rate = Droprate;
    HP_regain = HP;
}

bool food::is_gun() const
{
    return false;
}

bool food::is_melee() const
{
    return false;
}

bool food::is_armor() const
{
    return false;
}

bool food::is_food() const
{
    return true;
}

void food::print_names() const
{
    cout << name << endl;
}