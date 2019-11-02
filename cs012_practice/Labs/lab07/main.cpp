//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#>/main.cpp 
/// @brief Assignment/Lab 6 for CS 12 <spring 2015>
///
/// @author <Cole Resetco> [crese002@ucr.edu]
/// @date <5/14/2015>
///
/// @par Enrollment Notes 
///     Lecture Section: <001>
/// @par
///     Lab Section: <e.g. 021>
/// @par
///     TA: <lab guy>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============


#include <iostream>
#include <vector>
#include <cstdlib>
#include "IntVector.h"

using namespace std;

int main()
{
    // cout << "Test of vector size/cap: 7, Data: 5" << endl;
    // IntVector v(7,5);
    // cout << v.size() << endl;
    // cout << v.capacity() << endl;
    // cout << v.empty() << endl;
    // cout << v.at(4) << endl;
    // v.~IntVector();
    
    // cout << "*****************************" << endl;
    
    // cout << "Test of vector size/cap: 8, Data: 3" << endl;
    // IntVector q(8,3);
    // cout << q.size() << endl;
    // cout << q.capacity() << endl;
    // cout << q.empty() << endl;
    // cout << q.at(4) << endl;
    // cout << "Test of vector data change: q.at(4) = 5" << endl;
    // q.at(4) = 5;
    // cout << q.at(4) << endl;
    
    
    // cout << "*****************************" << endl;
    // cout << "Test of vector size/cap: 2, Data: 7" << endl;
    // IntVector r(2,7);
    // cout << r.size() << endl;
    // cout << r.capacity() << endl;
    // cout << r.empty() << endl;
    // cout << "Testing cout of .at that is outside of bounds:" << endl;
    // cout << r.at(4) << endl;
    
    // cout << "*****************************" << endl;
    // cout << "Test of an empty vector" << endl;
    // IntVector s(0,0);
    // cout << s.size() << endl;
    // cout << s.capacity() << endl;
    // cout << s.empty() << endl;
    // cout << "Will not test .at function as will result in seg fault" << endl;
    
    // cout << "*****************************" << endl;
    // cout << "Test of a vector (2,3) that is being expanded" << endl;
    // IntVector t(2,2);
    // cout << t.size() << endl;
    // cout << t.capacity() << endl;
    // t.expand();
    // cout << t.size() << endl;
    // cout << t.capacity() << endl;
    
    cout << "*****************************" << endl;
    cout << "Test of a vector with an insert/front/back" << endl;
    IntVector a(5,3);
    cout << a.size() << endl;
    cout << a.capacity() << endl;
    for(int i = 0; i < a.size(); ++i)
    {
        cout << a.at(i) << endl;
    }
    cout << "end" << endl;
    a.insert(3,7);
    for(int i = 0; i < a.size(); ++i)
    {
        cout << a.at(i) << endl;
    }
    
    cout << endl;
    cout << a.size() << endl;
    cout << a.capacity() << endl;
    cout << a.front() << endl;
    cout << a.back() << endl;
    a.erase(3);
    
    // cout << "*****************************" << endl;
    // cout << "Test of a vector with push back and pop back" << endl;
    // IntVector b(5,3);
    // cout << b.size() << endl;
    // cout << b.capacity() << endl;
    // b.push_back(6);
    // cout << "----" << endl;
    // b.pop_back();
    // b.resize(7);
    // b.resize(4);
    // b.resize(7, 7);
    // b.resize(4, 2);
    // b.assign(5, 7);
    // cout << b.capacity() << endl;
    // b.reserve(100);
    // cout << b.capacity() << endl;
    
    
    
    
    return 0;
}