#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>

#define BOOLEAN int
#define TRUE 1
#define FALSE 0

using namespace std;

int main()
{
    srand(time(NULL));
    int n = 10000;
    float my_rand; 
    float total;
    float mean;
    float pass_2;
    vector <float> mean_vector;
    vector <float> SD1_vector;
    vector <float> SD2_vector;
    
    vector <vector <float> > mainVector;
    for(int j = 0; j < 11; j++)
    {
        mainVector.push_back( vector <float>());
        for(int k = 0; k < n; k++)
        {
            my_rand = rand();
            my_rand =(my_rand/RAND_MAX) + 1000000000;
            mainVector.at(j).push_back(my_rand);
        }
    }
    

    for(int a = 0; a < mainVector.size(); a++)
    {
        total = 0;
        mean = 0;
        
        //Mean loop---------------------------
        for(int b = 0; b < mainVector.at(a).size(); b++)
        {
            total += mainVector.at(a).at(b);
            //cout << mainVector.at(a).at(b) << endl;
        }
        mean  =  total/n;
        
        cout << "mean number" << a + 1 << ": " << mean << endl;
        mean_vector.push_back(mean);
        
        
        pass_2 = 0;
        //SD loop--------------------------------
        for(int c = 0; c < mainVector.at(a).size(); c++)
        {
            pass_2 += pow((mainVector.at(a).at(c) - mean), 2);
            //cout << pass_2 << endl;
        }
        //cout << n << endl;
        float temp = 1;
        //float confidence = 0;
        temp =  temp/(n-1);
        //cout << temp << endl;
        pass_2 = pass_2*(temp);
        //confidence = 1.96 * (sqrt(pass_2/n));
        
        cout << "pass 2: " << pass_2 << endl;
        SD1_vector.push_back(pass_2);
        
        
        //SD single pass loop----------------------------
        float temp_mean = 0;
        float temp_total = 0;
        float mean_total = 0;
        float final_total = 0;
        for(int d = 0; d < mainVector.at(a).size(); d++)
        {
            mean_total += mainVector[a][d];
            temp_total += pow(mainVector[a][d], 2);
        }
        temp_mean = n*(pow(mean_total/mainVector.at(a).size(), 2));
        final_total =  temp_total - temp_mean;
        final_total = temp*final_total;
        
        cout << "pass 1: " << final_total <<endl;
        SD2_vector.push_back(final_total);
        
        
        

    }
    //Averaging------------------------------
    float add_mean = 0;
    float add_SD1 = 0;
    float add_SD2 = 0;
    
    for(int j = 0; j < 11; j++)
    {
        add_mean += mean_vector.at(j);
        add_SD1 += SD1_vector.at(j);
        add_SD2 += SD2_vector.at(j);
    }
    add_mean = add_mean/11;
    add_SD1 = add_SD1/11;
    add_SD2 = add_SD2/11;
    
    float sv_mean = 0;
    float sv_SD1 = 0;
    float sv_SD2 = 0;
    
    for(int i = 0; i < 11; i++)
    {
        sv_mean += pow((mean_vector.at(i) - add_mean) , 2);
        sv_SD1 += pow((SD1_vector.at(i) - add_SD1) , 2);
        sv_SD2 += pow((SD2_vector.at(i) - add_SD2) , 2);
    }
    
    float temp = 1;
    temp =  temp/(11-1);
    
    sv_mean = sv_mean * temp;
    sv_SD1 = sv_SD1 * temp;
    sv_SD2 = sv_SD2 * temp;
    
    cout << "means " << add_mean << " " << add_SD1 <<  " " <<  add_SD2 << endl;
    cout << "variences " << sv_mean <<  " " << sv_SD1 <<  " " <<  sv_SD2 << endl;
    
    //confidence intervals------------------------------
    float CI1_high =  add_mean + (2.228* (sqrt(sv_mean/11)));
    float CI1_low =  add_mean - (2.228* (sqrt(sv_mean/11)));
    
    float CI2_high =  add_SD1 + (2.228* (sqrt(sv_SD1/11)));
    float CI2_low =  add_SD1 - (2.228* (sqrt(sv_SD1/11)));
    
    float CI3_high =  add_SD2 + (2.228* (sqrt(sv_SD2/11)));
    float CI3_low =  add_SD2 - (2.228* (sqrt(sv_SD2/11)));
    
    cout << "Confidence Interval Mean between " << CI1_high << " and " << CI1_low << endl;
    cout << "Confidence Interval 2-pass between " << CI2_high << " and " << CI2_low << endl;
    cout << "Confidence Interval 1-pass between " << CI3_high << " and " << CI3_low << endl;
}