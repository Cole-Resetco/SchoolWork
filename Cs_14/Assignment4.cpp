//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn2/main.cpp 
/// @brief Assignment/Lab 7 for CS 12 q3 2015
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date June 4 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Lab Guy
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============






//NOTES//
//---pretty print isnt very pretty
//---this code does not work with an input file, you must eddit the vectors within main
//---was unable to get an algorithm for the 4th vector





#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

class node
{
    public:
        int curr_value;
        node *left;
        node *right;
        
        node() : curr_value(0), right(0), left(0) {};
        
        void setCurr(int val)
        {
            curr_value = val;
        }
};
void pretty_print_left(node *main, int comp_value, int &indent_level,
int & alternate_level_left, int & alternate_level_right)
{
    if(main-> left-> right != NULL)
    {
        alternate_level_left++;
    }
    if((main-> left != NULL) && (main-> left -> left != NULL))
    {
        indent_level++;
        pretty_print_left(main-> left, main-> curr_value, indent_level,
        alternate_level_left, alternate_level_right);
    }
    if((main-> left != NULL) && (main-> left -> left == NULL) && (main->left->right !=NULL))
    {
        indent_level++;
        pretty_print_left(main-> left, main-> curr_value, indent_level,
        alternate_level_left, alternate_level_right);
    }
    
  
    
        if((main-> left != NULL) && (main-> left -> left == NULL))
    {
        for(int k = indent_level - alternate_level_right; k > 0; k--)
        {
            cout << "  ";
        }
        for(int m = alternate_level_right; m > 0; m--)
        {
            cout << " |  ";
        }
        cout << "  / " << main->left->curr_value << endl;
    }
      if((main->right == NULL))
    {
        indent_level--;
        return;
    }
    
    if(comp_value > main->curr_value)
    {
        for(int j = indent_level - alternate_level_right; j > 0; j--)
        {
            cout << "  ";
        }
        for(int n = alternate_level_right; n > 0; n--)
        {
            cout << " |  ";
        }
        cout <<"/ " << main-> curr_value << endl;
    }
   
    if(comp_value <= main-> curr_value)
    {
        if(indent_level == 0)
        {
             cout <<"< " << main->curr_value << endl; 
        }
        else if((indent_level != 0) && (comp_value == main->curr_value))
        {
            indent_level--;
            return;
        }
        else
        {
            
            for(int i = indent_level - alternate_level_left; i > 0; i--)
            {
                cout << "  ";
            }
        for(int o = alternate_level_left; o > 0; o--)
            {
                cout << " |  ";
            }
            cout <<"\\ " << main->curr_value << endl; 
        }
    }
    //--- half way point --- //
    
     if(alternate_level_right > 0)
    {
    alternate_level_right--;
    }
    if(main-> right-> left != NULL)
    {
        alternate_level_right++;
    }
    
        
    if((main-> right != NULL) && (main-> right -> right != NULL))
    {
        indent_level++;
        pretty_print_left(main-> right, main-> curr_value, indent_level, 
        alternate_level_left, alternate_level_right);
    }
     if((main-> right != NULL) && (main-> right -> right == NULL) && (main->right->left !=NULL))
    {
        indent_level++;
        pretty_print_left(main-> right, main-> curr_value, indent_level,
        alternate_level_left, alternate_level_right);
    }
    
    
        if((main-> right != NULL) && (main-> right -> right == NULL))
    {
        for(int l = indent_level - alternate_level_left; l > 0; l--)
        {
            cout << "  ";
        }
        for(int p = alternate_level_left; p > 0; p--)
            {
                cout << " |  ";
            }
        cout << "  \\ " << main->right->curr_value << endl;
    }
    
    if((main->left == NULL))
    {
        indent_level--;
        return;
    }
         indent_level--;
        if(alternate_level_left > 0)
        {
            alternate_level_left--;
        }
        return;
    
}

// void pretty_print_right(node *main)
// {
//     if(main-> left != NULL)
//     {
//         cout << " " << endl;
//         pretty_print_left(main-> left);
//     }
//     if(main-> right != NULL)
//     {
//         cout << " " << endl;
//         pretty_print_right(main-> right);
//     }
//     if(main->right == NULL)
//     {
//         cout << main-> curr_value << endl;
//     }
//     return;
// }

void popualte_current(int current, node *main)
{
    if(current >= main->curr_value) //if value is bigger than or equal to base value
    {
        if(main-> right == NULL)
        {
            main-> right = new node;
            main-> right-> curr_value = current;
            main-> right-> left = NULL;
            main-> right-> right = NULL;
            cout << " populated: " << main-> right-> curr_value << endl;
            return;
        }
        
        if(main-> right != NULL)
        {
            popualte_current(current, main-> right);
            return;
        }
    }
    
    if(current < main->curr_value) //if value is bigger than or equal to base value
    {
        if(main-> left == NULL)
        {
            main-> left = new node;
            main-> left-> curr_value = current;
            main-> left-> left = NULL;
            main-> left-> right = NULL;
            cout << " populated: " << main-> left-> curr_value << endl;
            return;
        }
        
        if(main-> left != NULL)
        {
            popualte_current(current, main-> left);
            return;
        }
    }
    return;
    
}


int main()
{
    cout << "Begin" << endl;
    vector<int> test_list (15, 0);
    test_list.at(0) = 8;
    test_list.at(1) = 12;
    test_list.at(2) = 4;
    test_list.at(3) = 14;
    test_list.at(4) = 10;
    test_list.at(5) = 6;
    test_list.at(6) = 2;
    test_list.at(7) = 15;
    test_list.at(8) = 13;
    test_list.at(9) = 11;
    test_list.at(10) = 9;
    test_list.at(11) = 7;
    test_list.at(12) = 5;
    test_list.at(13) = 3;
    test_list.at(14) = 1;
    cout <<"Vector made" << endl;
    
     vector<int> test_list2 (15, 0);
    test_list2.at(0) = 8;
    test_list2.at(1) = 12;
    test_list2.at(2) = 4;
    test_list2.at(3) = 14;
    test_list2.at(4) = 10;
    test_list2.at(5) = 6;
    test_list2.at(6) = 2;
    test_list2.at(7) = 16;
    test_list2.at(8) = 13;
    test_list2.at(9) = 11;
    test_list2.at(10) = 9;
    test_list2.at(11) = 7;
    test_list2.at(12) = 5;
    test_list2.at(13) = 3;
    test_list2.at(14) = 1;
    
    vector<int> test_list3;
    vector<int> test_list4;
    
    for(int i = 0; i < test_list.size(); i++)
    {
        for(int j = 0; j < test_list2.size(); j++)
        {
            if(test_list.at(i) == test_list2.at(j))
            {
                test_list3.push_back(test_list.at(i));
                break;
            }
        }
    }
    int z = 0;
    int x = 0;
    bool match = false;
    
    while(z < test_list.size())
    {
        match = false;
        
        while( x < test_list2.size())
        {
            if(test_list.at(z) == test_list2.at(x))
            {
                match = true;
            }
            
            x++;
           
        }
        if(match == false)
        {
             test_list4.push_back(test_list.at(z));
             cout << "found: " << test_list.at(z) << endl;
        }
        z++;
        match = false;
    }
    
    
    
    node *main = new node();
    cout << "creating node" << endl;
    // cout << main-> curr_value << endl;
    
    main->setCurr(test_list.at(0));
    
    cout << "Given value" << endl;
    main-> left = NULL;
    main-> right = NULL;
    
    node *main2 = new node();
    cout << "creating node" << endl;
    // cout << main-> curr_value << endl;
    
    main2->setCurr(test_list2.at(0));
    
    cout << "Given value" << endl;
    main2-> left = NULL;
    main2-> right = NULL;
    
    node *main3 = new node();
    cout << "creating node" << endl;
    // cout << main-> curr_value << endl;
    
    main3->setCurr(test_list3.at(0));
    
    cout << "Given value" << endl;
    main3-> left = NULL;
    main3-> right = NULL;
    
    node *main4 = new node();
    cout << "creating node" << endl;
    // cout << main-> curr_value << endl;
    
    main4->setCurr(test_list4.at(0));
    
    cout << "Given value" << endl;
    main4-> left = NULL;
    main4-> right = NULL;
    
    cout << "Node made" << endl;
    
    for(int a = 1; a < test_list.size(); a++ )
    {
        cout << "Beginning recurtion" << endl;
        popualte_current(test_list.at(a), main);
        cout << test_list.at(a) << " Conceptualy popualted" << endl;
    }
    
    cout << endl;
    
    for(int b = 1; b < test_list2.size(); b++ )
    {
        cout << "Beginning recurtion" << endl;
        popualte_current(test_list2.at(b), main2);
        cout << test_list2.at(b) << " Conceptualy popualted" << endl;
    }
    
    cout << endl;
    
    for(int c = 1; c < test_list3.size(); c++ )
    {
        cout << "Beginning recurtion" << endl;
        popualte_current(test_list3.at(c), main3);
        cout << test_list3.at(c) << " Conceptualy popualted" << endl;
    }
    
    cout << endl;
    
    for(int d = 1; d < test_list4.size(); d++ )
    {
        cout << "Beginning recurtion" << endl;
        popualte_current(test_list4.at(d), main4);
        cout << test_list4.at(d) << " Conceptualy popualted" << endl;
    }
    
    cout << endl;
    
    cout << "Finished populating" << endl;
    
    cout << "End of program" << endl;
    int indent_level = 0;
    int alternate_level_left = 0;
    int alternate_level_right = 0;
    
    pretty_print_left(main, main-> curr_value, indent_level, alternate_level_left, alternate_level_right);
    
     cout << endl;
    
    indent_level = 0;
    alternate_level_left = 0;
    alternate_level_right = 0;
    
    pretty_print_left(main2, main2-> curr_value, indent_level, alternate_level_left, alternate_level_right);
     cout << endl;
    
    
    indent_level = 0;
    alternate_level_left = 0;
    alternate_level_right = 0;
    
    pretty_print_left(main3, main3-> curr_value, indent_level, alternate_level_left, alternate_level_right);
     cout << endl;
     
      indent_level = 0;
    alternate_level_left = 0;
    alternate_level_right = 0;
    
    pretty_print_left(main4, main4-> curr_value, indent_level, alternate_level_left, alternate_level_right);
     cout << endl;
    
    
    cout << "Finished printing" << endl;
    
    return 0;
}