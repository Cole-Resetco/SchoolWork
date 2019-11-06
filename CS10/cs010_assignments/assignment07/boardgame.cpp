//  =============== BEGIN ASSESSMENT HEADER ================
/// @file MontyCarlo:BoardGame.cpp
/// @brief Assignment 7
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date March 9, 2015
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============


#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//comment1
//comment2
//comment3

int rollNDice(int, int);
int mostLandings( vector <int> & , int , int);
void runSim(vector<int> &, int & );
int rollNDice(int numDice, int numSides){
    int ret=0;
    for(int i = 0; i < numDice; i++){
        ret = ret + ((rand()% numSides) + 1);
    }
    return ret;
}
int mostLandings( vector <int> &v, int beginValue, int endValue){
    int i = 0;
    int largest = -99;
    int posBiggest = -1;
    for(i = beginValue; i <= endValue; i++){
        if(v.at(i) > largest){
            largest = v.at(i);
            posBiggest = i;
        }
    }
    return posBiggest;
}
int main(){   
    srand(time(0));
    int numSides, numSpots, numSims;
    int i = 0;
    int posPiece = 0;
    int rollDice = 0;
    cout << "How many sides of the board are there? ";
    cin >> numSides;
    cout << endl;
    cout << "How many spots are on each side? ";
    cin >> numSpots;
    cout << endl;
    vector <int> v(numSides * numSpots);
    cout << "How many simulations? ";
    cin >> numSims;
    cout << endl;
    for(i = 0; i < v.size(); i++){
        v.at(i) = 0;
    }
    cout<<"The following spots on each side have the most landings: "<<endl;
    for(i = 0; i < numSims; i++){
        posPiece = 0;
        rollDice = 0;
        do{
            rollDice = rollNDice(2,6);
            posPiece = posPiece + rollDice;
            if(posPiece < v.size() && posPiece != 0){
                v.at(posPiece) = v.at(posPiece) + 1;
                continue;
            }
            else if(posPiece == (numSides * numSpots)){
                v.at(0) = v.at(0) + 1;
                break;
            }
            else{
                break;
            }
        }
        while(posPiece <= v.size());
    }
    v.push_back(v.at(0));
    for(i = 0; i < numSides; i++){
        cout << "On side " <<i + 1<< ", spot ";
        cout << mostLandings(v, (i * numSpots) + 1,((i + 1) * numSpots));
        cout << " has the most landings: ";
        cout << v.at(mostLandings(v, (i * numSpots) + 1,(i + 1) * numSpots));
        cout << endl;
    }
}