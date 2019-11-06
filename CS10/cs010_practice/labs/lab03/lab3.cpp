//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab03.cpp
/// @brief lab03
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date January, 22, 2015
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>


using namespace std;

int main() 
{
  double cents = 100;
  double purchaseAmount;
  double paidAmount;
  double change;
  int changePennies;
  int dollar;
  int quarter;
  int dime;
  int nickel;
  int pennie;
  // get purchase ammount 
  
  cout << "Enter purchase amount : $";
  cin >> purchaseAmount;
  cout << endl;
  
  // get paid amount
  
  cout << "Enter amount received : $";
  cin >> paidAmount;
  cout << endl;
  
  // convert to pennies
  
  change = static_cast<double>(paidAmount) - purchaseAmount;
  cout << "Total Change: " << "$" << change << endl;
  
  changePennies = static_cast<int>(change * cents + 0.5);
  cout << endl;
  
  
  
  // divide by dollars
  
  dollar = (changePennies / 100 + 0.5);
  cout << "dollars "<< dollar << endl;
  cout << endl;
  
  
  //divide by quarters
  
  quarter = (changePennies % 100 / 25 + 0.5);
  cout << "quarters " << quarter << endl;
  cout << endl;
  //divide by dimes
  
  dime = (changePennies % 100 % 25 / 10 + 0.5);
  cout << "dimes " << dime << endl;
  cout  << endl;
  //divide by nickles
  
  nickel = (changePennies % 100 % 25 % 10 / 5 + 0.5);
  cout << "nickels " << nickel << endl;
  cout << endl;
  
  //output all change and remaining pennies
  
  pennie = (changePennies % 100 % 25 % 10 % 5 + 0.5);
  cout << "pennies "<< pennie << endl;
  cout << endl;
  
  return 0;
}