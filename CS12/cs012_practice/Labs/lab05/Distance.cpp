#include <iostream>
#include "Distance.h"
#include <string>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

Distance::Distance()
{
    feet = 0;
    inches = 0.0;
    init();
}

Distance::Distance(unsigned ft, double in)
{
    feet = ft;
    if (in < 0)
    {
        inches = -1 * in;
    } else
    {
        inches = in;
    }
    init();
}

Distance::Distance(double in)
{
    feet = 0;
    if (in < 0)
    {
        inches = -1 * in;
    } else
    {
        inches = in;
    }
    init();
}

void Distance::init()
{
    if (inches >= 12.0)
    {
        feet = feet + static_cast<int>(inches / 12);
        inches = inches - ((static_cast<int>(inches) / 12) * 12);
    }
}

double Distance::convertToInches() const
{
    return (feet * 12 + inches);
}

const Distance Distance::operator+(const Distance &b) const
{
    Distance a;
    a.convertToInches();
    b.convertToInches();
    a.feet = feet + b.feet;
    a.inches = inches + b.inches ;
    a.init();
    return a;
}

const Distance Distance::operator-(const Distance &b) const
{
    Distance a;
    a.convertToInches();
    b.convertToInches();
    int nigCheck = feet - b.feet;
    if (nigCheck < 0)
    {
        a.feet = b.feet - feet;
        a.inches = b.inches - inches;   
    }
    if (inches > b.inches)
    {
        a.feet = feet - b.feet;
        a.inches = inches - b.inches ;
        a.init();
        return a;
    }
    else
    {
        a.feet = b.feet - feet;
        a.inches = b.inches - inches ;
        a.init();
        return a;
    }
    
}

void Distance::display() const
{
    
    cout << "Feet: " << feet << "' Inches: " << inches << '"';
}