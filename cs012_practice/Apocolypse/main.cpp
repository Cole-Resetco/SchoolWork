#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Interface.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "ERROR NOT ENOUGH ARGUMENTS" << endl;
        return 0;
        
    }

    string datafile(argv[1]);
    
    string my_Apocolypse;
    
    cout << "Creating interface..." << endl;
    
    cout << "NAME YOUR APOCOLYPSE" << endl;
    
    // cin >> my_Apocolypse;
    // Interface Int(my_Apocolypse);
    
    Interface Int("My Apocolypse");
    
    cout << "Loading items..." << endl;
    
    Int.import_items(datafile);
    
    cout << "Items loaded, Running" << endl;
    
    Int.begin_interface();
    Int.list_items();
    
    return 0;
    
    
}