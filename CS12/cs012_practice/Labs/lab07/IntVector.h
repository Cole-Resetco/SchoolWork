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

using namespace std;

class IntVector
{
    private:
        unsigned sz;
        unsigned cap;
        int *data;
    
    public:
        IntVector();//                           | All done/tested
        IntVector(unsigned size);//              |    |
        IntVector(unsigned size, int value);//   |    |
        ~IntVector(); //                         |    |
        unsigned size() const;//                 |    |
        unsigned capacity() const;//             |    |
        bool empty() const;//                    |    |
        const int & at(unsigned index) const; // |    v
        //-------------------------------------- Done/Tested 
        int & at(unsigned index); //             Done/Tested
        
        void insert(unsigned index, int value);//Done/Tested
        void erase(unsigned index);//            Done/Tested
        const int & front() const; //            Done/Tested
        int & front(); //                        Done/Tested
        const int & back() const; //             Done/Tested
        int & back(); //                         Done/Tested
        void assign(unsigned n, int value);//    Done/Tested
        void push_back(int value);//             Done/Tested
        void pop_back();//                       Done/Tested
        void clear();//                          Done/Tested
        void resize(unsigned size);//            Done/Tested
        void resize(unsigned size, int value);// Done/Tested
        void reserve(unsigned n);//              Done
        //                                       |
    private://                                   |
        void expand(); //                        Done/ Apears to work
        void expand(unsigned amount); //         Done/ Appears to work


};
