// This program implements the Monte Carlo Method for estimating the value of PI.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <math.h>
#include <vector>

using namespace std;

int search(const vector<int>& v, int num)
{
    int returnNum;
    for(int i = 0; i < v.size(); i++)
    {
        if (v.at(i) == num)
        {
            returnNum = i;
            return returnNum;
        }
    }
    returnNum = -1;
    return returnNum;
}

void remove(vector<int>& v, int num)
{
    for ( int i = num; i < v.size()-1; i++)
    {
        v.at(i) = v.at(i+1);
    }
    v.pop_back();
}



int main()
{
    int removeNum;
    int tempInt;
    int search1;
    vector<int> v;
    cout << "Please enter in intergers (0 to stop):";
    cin >> tempInt;
    while (tempInt != 0)
    {
        v.push_back(tempInt);
        cin >> tempInt;
    }
    
    cout << "What number would you like to find and remove?: ";
    cin >> removeNum;
    search1 =  search(v, removeNum);
    cout << "Found: " << search1 << endl;
    if (search1 != -1)
    {
        remove(v, search1);
    }
    cout << "Result: ";
    for( int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    
    return 0;
    
}