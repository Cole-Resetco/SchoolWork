//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab07.cpp
/// @brief lab7/Branches and Chars
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date February, 19, 2015
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int genRandInt(int int1, int int2) // if int1 = 30/ int2 = 60
/* 
/   creates function containing parameters of ints 1 and 2
*/


{
    int randNumber;
    
    randNumber = ((rand() % (int2 - int1 + 1)) + int1 );
    
    return randNumber;
}

int main()
{
    srand(time(0)); //seeds randum numbers to the time
    int ex;
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;
    if (1 == ex)
    {
        int lowerBound;
        int upperBound;
        
        cout << "Enter the smallest possible number: ";
        cin >> lowerBound;
        cout << endl;
        
        cout << "Enter the largest possible number: ";
        cin >> upperBound;
        cout << endl;
        
        
        
        cout << "Random number: " << genRandInt(lowerBound, upperBound) << endl;
        cout << "Random number: " << genRandInt(lowerBound, upperBound) << endl;
        cout << "Random number: " << genRandInt(lowerBound, upperBound) << endl;
        
        return 0;
    }


    else if (2 == ex)
    {
        int coinFlip;
        string coinToss;
        
        do
        {
            coinFlip = genRandInt( 1, 2 );
            
            if ( coinFlip == 1 )
            {
                cout << "Flip: heads" << endl;
            }
            else if ( coinFlip == 2 )
            {
                cout << "Flip: tails" << endl;
            }
            
            cout << "Toss the coin again (yes/no)? ";
            cin  >> coinToss;
            cout << endl;
            
        } while ( coinToss != "no" );
        return 0;
    }
}