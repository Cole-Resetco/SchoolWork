//  =============== BEGIN ASSESSMENT HEADER ================
/// @file isbn.cpp
/// @brief Assignment 3
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date February 1, 2015
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <ios>

using namespace std;

/* first off, lets start by making a dice roll function that roles
|  the amount of time the user says, and outputs the sum EDIT:---> done
*/

/* next lets create a way for the function to stop after the sum reaches 
|  a certain number as defined by the user
|
|  CHECK: lets get to outputing score 0 and the other six possible scores in 
|  the right place
*/


int genRandInt (int minNum, int maxNum)
{
    return (rand() % (maxNum - minNum + 1)) + minNum;
}

int singleTurn (int holdNum)
{
    int dieRoll = 0;
    int score = 0;
    
    do
    {
        dieRoll = genRandInt (1 , 6);   
        score += dieRoll;
    } while (dieRoll != 1 && score < holdNum);
    
    if (dieRoll == 1)
    {
        score = 0;
    }
    return score;
}


int main()
{

    
    
    srand(time(0));
    int hold;
    int score;
    double Nturns;
    int score0 = 0;
    int scorehold1 =  0;
    int scorehold2 =  0;
    int scorehold3 =  0;
    int scorehold4 =  0;
    int scorehold5 =  0;
    int scorehold6 =  0;
    
    
    cout << "What value should we hold at? ";
    cin >> hold;
    cout << endl;
    
    cout << "Hold-at-N turn simulations? ";
    cin >> Nturns;
    cout << endl;
    
    cout << "Score\t" << "Estimated Probability" << endl;
    
    
    for (int i = 1; i <= Nturns; i++)
    {
        score = singleTurn(hold);
        if (score == 0)
        {
            score0++;
        }
        
        else if (score == hold)
        {
            scorehold1++;
        }
        
        else if (score == (hold + 1))
        {
            scorehold2++;
        }
        
        else if ( score ==(hold + 2))
        {
            scorehold3++;
        }
        
        else if ( score == (hold + 3))
        {
            scorehold4++;
        }
        
        else if ( score == (hold+ 4))
        {
            scorehold5++;
        }
        
        else if ( score == (hold + 5))
        {
            scorehold6++;
        }
        
    }
    
    
    
    
    cout << "0\t" << fixed << setprecision(6) << score0 / Nturns << endl;
    cout << hold << "\t" << fixed << setprecision(6) << scorehold1 / Nturns
    << endl;
    cout << hold + 1 << "\t" << fixed << setprecision(6) << scorehold2 / 
    Nturns << endl;
    cout << hold + 2 << "\t" << fixed << setprecision(6) << scorehold3 / 
    Nturns << endl;
    cout << hold + 3 << "\t" << fixed << setprecision(6) << scorehold4 / 
    Nturns << endl;
    cout << hold + 4 << "\t" << fixed << setprecision(6) << scorehold5 / 
    Nturns << endl;
    cout << hold + 5 << "\t" << fixed << setprecision(6) << scorehold6 / 
    Nturns << endl;
    
    return 0;

}