//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab04.cpp
/// @brief lab4/Branches and Chars
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date January, 29, 2015
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>

using namespace std;

#include <iostream>
using namespace std;
int main()
{

 int ex;
     cout << "Which exercise? ";
     cin >> ex;
     cout << endl;
     if (1 == ex)

 {
   string word;
    cout << "Enter a word: ";
    cin >> word;
    
    for (int i = 0; i < word.size(); ++i) {
      if (word.at(i) == 'e') {
        //cout << '3';
        //cout << word.at(i);
        word.at(word.find('e')) = '3';
        //cout << word.at(i);
      }
      
      else if (word.at(i) == 'i') {
        //cout << '1';
        //cout << word.at(i);
        word.at(word.find('i')) = '1';
        
      }
      
      else if (word.at(i) == 'x') {
        //cout << '*';
        //cout << word.at(i);
        word.at(word.find('x')) = '*';
        
      }
       
         
       
      
      
    }
    cout << endl;
    cout << "Your word transformed is " << word << endl;
 // All Exercise 1 code

 }

 else if (2 == ex)
 {
   string word2;
   int period = 0;
   int periodind = 0;
   int stopind = 0;
   int stop = 0;
   cout << "Enter a word: ";
   cin >> word2;
 
  for (int i = 0; i < word2.size(); ++i) 
  {
   if (word2.at(i) == '.') 
   {
     period = 1;
     periodind = i;
   }
   
   if (word2.at(i) == 's') 
   {
     if (word2.at(i+1) == 't') 
     {
       if (word2.at(i+2) == 'o') 
       {
         stop = 1;
         stopind = i;
       }
     }
   }
     
   }
   if (period == 1) 
   {
     cout << "  " << periodind << endl;
   }
   
   if (stop == 1) 
   {
     cout << "yayaya " << stopind <<  endl;
   }
   
 
 

 } 


 return 0;


}