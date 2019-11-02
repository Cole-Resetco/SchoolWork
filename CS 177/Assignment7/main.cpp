#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    float e  = 2.71828;
    vector <float> values;
    
    for (int i = 0; i < 32; i++)
    {
        float temp = (((float)rand())/RAND_MAX);
        cout << "Uniform: " << temp << endl;
        values.push_back((-2 * log(temp)));
        cout << values.at(i) << endl;;
    }
    
    //float x = values.at(0);
    //float y = values.at(1);
    float di;
    //float di2;
    
    //---------------Sort------------------
    float max = 0;
    for (int j = 0; j < values.size(); j++)
    {
        if(values.at(j) > max)
        {
            max = values.at(j);
        }
    }
    
    cout << "Max: " << max << endl;
    
    
    cout << "First Value Distribution" << endl;
    float total = 1;
    for (int a = 1; a < 50; a++)
    {
        float temp = 0;
        for(int k = 0; k  < 32; k++)
        {
            temp+= values.at(k);
            //cout << "temp: " << temp << endl;
            //total = 1.0/a;
            //total = pow(total, 32);
            //di = (2 * (a -(values.at(k))))/(a*a);
            //total = total * di;
            //cout << "sub total: " << total << endl;
        }
        
        total = a * pow(e, -a * values.at(0));
        //total = (-32 * (log(a))) - ((float)(1/a) * temp);
        //cout << -a * values.at(0) << endl;
        //cout << "total " << total << endl;
        //total = pow(a, 16) * total;
        
        //di = (2 * (a -(values.at(0))))/(a*a);
        //di2 = (2 * (a-y))/(a*a);
        //di = di * di2;
        //total = 1.0/a;
        if(a < max)
        {
           //total = 0;
        }
        
        cout << total << endl;
        total = 1;
    }
}
