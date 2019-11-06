//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#>/main.cpp 
/// @brief Assignment/Lab 6 for CS 12 <spring 2015>
///
/// @author <Cole Resetco> [crese002@ucr.edu]
/// @date <5/21/2015>
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


#ifndef INTLIST_H
#define INTLIST_H

#include <cstdlib>
#include <iostream>


using namespace std;

struct IntNode

{
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};

class IntList
{
    private:
        IntNode *head;
        IntNode *tail;
        
    public:
        IntList();
        ~IntList();
        void display() const;
        void push_front(int value);
        void pop_front();
        void push_back(int value);
        void select_sort();
        void insert_sorted(int value);
        void remove_duplicates();
        void displayeverse(IntNode *curr);
        void displayReverse() const;
};

#endif