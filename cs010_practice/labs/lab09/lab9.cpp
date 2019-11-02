//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab9.cpp
/// @brief lab09
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date March, 5, 2015
//  ================== END ASSESSMENT HEADER ===============




#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

void fillVector(vector <double> &);
double average(const vector <double> &);
double standardDeviation(const vector <double> &);

 
int main()
{
    return 0;
}

void fillVector(vector <double> &v)
{
    double d;
    while (cin >> d)
    {
        v.push_back(d);
    }
}

double average(const vector <double> &v)
{
    double sum = 0.;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v.at(i);
    }

    return sum / v.size();
}

double standardDeviation(const vector <double> &v)
{
    double sum = 0;
    double standDev = 0;
    double mean = average(v);
    
    for(int i = 0; i < v.size(); i++)
    {
        sum += pow((v.at(i)- mean), 2);
    }
    
    standDev = sqrt (sum/v.size());
    
    //hey look; in theory this should take the standard deviation... Go figure
    
    return standDev;
}