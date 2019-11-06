#include <iostream>
#include "Date.h"
#include <string>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
Date::Date()
{
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}
 
Date::Date(unsigned m, unsigned d, unsigned y)
{
    month = m;
    day = d;
    year = y;
    monthName = name(m);
}
 
Date::Date(const string &mn, unsigned d, unsigned y)
{
    monthName = mn;
    day = d;
    year = y;
    month = number(mn);
    if (month > 12)
    {
        month = 12
    }
   
    if (day > daysPerMonth(month, year))
    {
        day = daysPerMonth(month, year);
    }
    if (m > 12 || d > daysPerMonth(month, year))
    {
        cout << "Invalid date values: Date corrected to " <<
    }
}
 
void Date::printNumeric() const
{
    cout << month << "/" << day << "/" << year << endl;
}
 
void Date::printAlpha() const
{
    cout << monthName << " " << day << ", " << year << endl;
}
 
bool Date::isLeap(unsigned) const
{
    if (year % 400 == 0)
    {
        return true;
    } else if (year % 100 == 0)
    {
        return false;
    } else if (year % 4 == 0)
    {
        return true;
    }
}
 
unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
    if (m == 2 && isLeap(y))
    {
        return 29;
    }
    else if (m == 2)
    {
        return 28;
    }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 12)
    {
        return 31;
    } else
    {
        return 30;
    }
}
 
string Date::name(unsigned m) const
{
    if (m == 1)
    {
        return "January";
    }
    if (m == 2)
    {
        return "February";
    }
    if (m == 3)
    {
        return "March";
    }
    if (m == 4)
    {
        return "April";
    }
    if (m == 5)
    {
        return "May";
    }
    if (m == 6)
    {
        return "June";
    }
    if (m == 7)
    {
        return "July";
    }
    if (m == 8)
    {
        return "August";
    }
    if (m == 9)
    {
        return "September";
    }
    if (m == 10)
    {
        return "October";
    }
    if (m == 11)
    {
        return "November";
    }
    if (m == 12)
    {
        return "December";
    }
}
 
unsigned Date::number(const string &mn) const
{
    if (mn == "January" || mn == "january")
    {
        return 1;
    }
    if (mn == "February" || mn == "february")
    {
        return 2;
    }
    if (mn == "March" || mn == "march")
    {
        return 3;
    }
    if (mn == "April" || mn == "april")
    {
        return 4;
    }
    if (mn == "May" || mn == "may")
    {
        return 5;
    }
    if (mn == "June" || mn == "june")
    {
        return 6;
    }
    if (mn == "July" || mn == "july")
    {
        return 7;
    }
    if (mn == "August" || mn == "august")
    {
        return 8;
    }
    if (mn == "September" || mn == "september")
    {
        return 9;
    }
    if (mn == "October" || mn == "october")
    {
        return 10;
    }
    if (mn == "November" || mn == "november")
    {
        return 11;
    }
    if (mn == "December" || mn == "december")
    {
        return 12;
    }
}


#include <iostream>
#include "Date.h"
#include <vector>
#include <string>

using namespace std;


Date::Date()
{
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
    day = d;
    month = m;
    year = y;
    monthName = name(m);
    
}

Date::Date(const string &mn, unsigned d, unsigned y)
{
    day = d;
    monthName = mn;
    year = y;
    month = number(mn);
    if (month > 12)
    {
        month = 12;
    }
   
    if (day > daysPerMonth(month, year))
    {
        day = daysPerMonth(month, year);
    }
    if (mn > 12 || d > daysPerMonth(month, year))
    {
        cout << "Invalid date values: Date corrected to " << mn << ' ' << d <<
        ", " << y;
    }
}

bool Date::isLeap(unsigned) const
{
    if (year % 400 == 0)
    {
        return true;
    } else if (year % 100 == 0)
    {
        return false;
    } else if (year % 4 == 0)
    {
        return true;
    }
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
    if (m == 2 && isLeap(y))
    {
        return 29;
    }
    else if (m == 2)
    {
        return 28;
    }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 12)
    {
        return 31;
    } else
    {
        return 30;
    }
}

unsigned Date::number(const string &mn) const
{
    if (mn == "January" || mn == "january")
    {
        return 1;
    }
    if (mn == "February" || mn == "february")
    {
        return 2;
    }
    if (mn == "March" || mn == "march")
    {
        return 3;
    }
    if (mn == "April" || mn == "april")
    {
        return 4;
    }
    if (mn == "May" || mn == "may")
    {
        return 5;
    }
    if (mn == "June" || mn == "june")
    {
        return 6;
    }
    if (mn == "July" || mn == "july")
    {
        return 7;
    }
    if (mn == "August" || mn == "august")
    {
        return 8;
    }
    if (mn == "September" || mn == "september")
    {
        return 9;
    }
    if (mn == "October" || mn == "october")
    {
        return 10;
    }
    if (mn == "November" || mn == "november")
    {
        return 11;
    }
    if (mn == "December" || mn == "december")
    {
        return 12;
    }
}

string Date::name(unsigned m) const;
{
     if (m == 1)
    {
        return "January";
    }
    if (m == 2)
    {
        return "February";
    }
    if (m == 3)
    {
        return "March";
    }
    if (m == 4)
    {
        return "April";
    }
    if (m == 5)
    {
        return "May";
    }
    if (m == 6)
    {
        return "June";
    }
    if (m == 7)
    {
        return "July";
    }
    if (m == 8)
    {
        return "August";
    }
    if (m == 9)
    {
        return "September";
    }
    if (m == 10)
    {
        return "October";
    }
    if (m == 11)
    {
        return "November";
    }
    if (m == 12)
    {
        return "December";
    }
}

void Date::printNumeric() const
{
    
    cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const
{
    name(monthName) const;
    cout << monthName << " " << day <<", " << year;
}