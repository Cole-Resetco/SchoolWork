//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab2.cpp
/// @brief Madlib
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date January, 19, 2015
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>

using namespace std;

int main() 
{

  string yourName;
  string yourPlace;
  string yourBodyPart;
  string yourFamilyMember;
  string yourFood;
  string yourVerb;
  string yourVerb2;
  string yourPlace2;
  string yourBodyPart2;
  string yourAnimal;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Please enter your first name ";
    cin >> yourName;
    cout << endl;
    
    cout << "Please enter a place ";
    cin >> yourPlace;
      cout << endl;
    
    cout << "Please enter a body part ";
    cin >> yourBodyPart;
      cout << endl;
    
    cout << "Please enter a Family Member ";
    cin >> yourFamilyMember;
      cout << endl;
    
    cout << "Please enter a Food ";
    cin >> yourFood;
      cout << endl;
    
    cout << "Please enter a past tense verb ";
    cin >> yourVerb;
      cout << endl;
    
    cout << "Please enter a past tense verb ";
    cin >> yourVerb2;
      cout << endl;
    
    cout << "Please enter a Place ";
    cin >> yourPlace2;
      cout << endl;
    
    cout << "Please enter a body part ";
    cin >> yourBodyPart2;
      cout << endl;
    
    cout << "Please enter an animal ";
    cin >> yourAnimal;
    cout << endl;
    cout << endl;
    
        cout << "--------------------------------------------------------------------------------" << endl;
    cout << "There once was a kid named " << yourName << "." << endl;
    cout << "One day he went to " << yourPlace << "." << endl;
    cout << "Unfortunately he broke his " << yourBodyPart << " while there." << endl;
    cout << endl;
    cout << "He went to his " << yourFamilyMember << "'s house." << endl;
    cout << "and his " << yourFamilyMember << " fed him lots of " << yourFood << "." << endl;
    cout << "It was so good he " << yourVerb << " for joy." << endl;
    cout << "He " << yourVerb << " so hard he " << yourVerb2 << " away." << endl;
    cout << endl;
    cout << "After he healed he went to " << yourPlace2 << " to celebrate." << endl;
    cout << "Sadly he broke his " << yourBodyPart2 << " shortly after." << endl;
    cout << "And that made him a very sad " << yourAnimal << "." << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
    
    

}