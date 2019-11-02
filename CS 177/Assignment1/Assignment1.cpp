
///Cole Resetco [crese002@ucr.edu]
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <stdlib.h>

using namespace std;



bool in_circle(double& coordx, double& coordy)
{
    float Check_pi = pow(coordx, 2) + pow(coordy, 2);
    //cout << "Check_pi: " << Check_pi << endl;
    if(Check_pi <= 1)
    {
        //cout << "Check_pi: " << Check_pi << endl;
        return true;

    }
    else
    {
        //cout << "found false" << endl;
        return false;
    }
}

double new_pi_sequence(const int& N)
{
     double pi_estimate = 0;
    double count = 0;
    double total = 0;
    ofstream myfile;
    myfile.open("main2.csv");
    
    for(int i = N; i > 0; i--)
    {
        double rx = rand();
        double ry = rand();
        rx = static_cast <double> (rand()) / static_cast <double> (RAND_MAX/(1 - 0));
        ry = static_cast <double> (rand()) / static_cast <double> (RAND_MAX/(1 - 0));
        
        if(rx + ry >= 1)
        {
            total++;
            if(pow(rx, 2) + pow(ry, 2) <= 1)
            {
                count++;
            }
        }
        
        if(total != 0)
        {
            pi_estimate = (2*(count/total)) + 2;
        }
        //cout << pi_estimate << endl;
        myfile << pi_estimate <<endl;
        

        
    }
    
    myfile << endl;
    return pi_estimate;
}

double pi_sequence(const int& N)
{
    double pi_estimate = 0;
    double count = 0;
    double total = 0;
    ofstream myfile;
    myfile.open("main.txt");
    
    for(int i = 2000; i > 0; i--)
    {
        double rx = rand();
        double ry = rand();
        rx = static_cast <double> (rand()) / static_cast <double> (RAND_MAX/(1 - 0));
        ry = static_cast <double> (rand()) / static_cast <double> (RAND_MAX/(1 - 0));
        
        if(in_circle(rx, ry) == true)
        {
            count++;
        }
        total++;
        
        pi_estimate = ((count/total)* 4);
        myfile <<  pi_estimate << ", ";
        
    }
    myfile << endl;
    myfile.close();
    return pi_estimate;
}

double estimate_pi(const int& N)
{
    
    double count = 0;
    

    for(int i = N; i > 0; i--)
    {
        double rx = rand();
        double ry = rand();
        rx = static_cast <double> (rand()) / static_cast <double> (RAND_MAX/(1 - 0));
        ry = static_cast <double> (rand()) / static_cast <double> (RAND_MAX/(1 - 0));
        
        //cout << "rx/ry: " << rx << "/" << ry << endl;
        
        if(in_circle(rx, ry) == true)
        {
            count++;
            //cout << " Incremented Count" << endl;
        }
    }
    return count;
}

int main()
{
    srand(time(NULL));
    float pi =  3.14159264;
    float pi_find = 0;

    double count_fin = 0;
    int Attempts = 1;
    count_fin = estimate_pi(Attempts);
    cout << "N             Estimate          Difference" << endl;
    cout << Attempts << "             " << ((count_fin/Attempts)* 4) << "                  " << ((count_fin/Attempts)* 4) - pi <<endl;
    
    Attempts = 10;
    count_fin = estimate_pi(Attempts);
    cout << Attempts << "            " << ((count_fin/Attempts)* 4) <<"                 " << ((count_fin/Attempts)* 4) - pi <<endl;
        
    Attempts = 100;
    count_fin = estimate_pi(Attempts);
    cout << Attempts << "           " << ((count_fin/Attempts)* 4) << "                " << ((count_fin/Attempts)* 4) - pi <<endl;
    
    
        Attempts = 1000;
    count_fin = estimate_pi(Attempts);
    cout << Attempts << "          " << ((count_fin/Attempts)* 4) << "               " << ((count_fin/Attempts)* 4) - pi <<endl;
    
    
        Attempts = 10000;
    count_fin = estimate_pi(Attempts);
    cout << Attempts << "         " << ((count_fin/Attempts)* 4) << "              " << ((count_fin/Attempts)* 4) - pi <<endl;
    
    
            Attempts = 100000;
    count_fin = estimate_pi(Attempts);
    cout << Attempts << "        " << ((count_fin/Attempts)* 4) << "              " << ((count_fin/Attempts)* 4) - pi <<endl;
    
    
            Attempts = 1000000;
    count_fin = estimate_pi(Attempts);
    cout << Attempts << "       " << ((count_fin/Attempts)* 4) << "              " << ((count_fin/Attempts)* 4) - pi <<endl;
    
    
            Attempts = 10000000;
    count_fin = estimate_pi(Attempts);
    cout << Attempts << "      " << ((count_fin/Attempts)* 4) << "              " << ((count_fin/Attempts)* 4) - pi <<endl;
    

    Attempts = 2000;
    pi_find = pi_sequence(Attempts);
    
    pi_find = new_pi_sequence(Attempts);
    


    
    

    
}
