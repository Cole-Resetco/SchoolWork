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


#include <cstdlib>
#include <iostream>
#include "IntList.h"

using namespace std;

 
IntList::IntList()
{
    head = NULL;
    tail = NULL;
}
 
IntList::~IntList()
{
    IntNode* current = head;
    while(current)
    {
        IntNode* temp = current->next;
        delete current;
        current = temp;
    }
}
 
void IntList::display() const
{
    IntNode* current = head;
    while(current != NULL)
    {
        cout << current->data;
        current = current->next;
        if (current)
        {
            cout << " ";
        }
    }
}
 
void IntList::push_front(int value)
{
    IntNode* newVal = new IntNode(value);
    newVal->next = head;
    head = newVal;
    if (tail == NULL)
    {
        tail = head;
    }
}
 
void IntList::pop_front()
{
    if (head != 0)
    {
        IntNode* temp = head;
        head = head->next;
        delete temp;
    }
    if (head == 0)
    {
        tail = 0;
    }
}

void IntList::push_back(int value)
{
    IntNode *temp = new IntNode(value);
    if (tail == NULL)
    {
        tail = temp;
    }
    temp->next = 0;
    tail->next = temp;
    tail = temp;
    if (head == 0)
    {
        head = temp;
    }
}
 
void IntList::select_sort()
{
    for (IntNode *i = head; i != 0; i = i->next)
    {
        IntNode *smallest = i;
        for (IntNode *j = i; j != 0; j = j->next)
        {
            if (j->data < smallest->data)
            {
                smallest = j;
            }
        }
        int temp = i->data;
        i->data = smallest->data;
        smallest -> data = temp;
    }
}
 
void IntList::insert_sorted(int value)
{
    IntNode* current = head;
    if (head == NULL)
    {
        push_front(value);
    }
    if (tail == head)
    {
        if (value > head->data)
        {
            push_back(value);
        } else
        {
            push_front(value);
        }
    }
    if (head != tail)
    {
        while(current->next)
        {
            IntNode* temp = current->next;
            if (value < temp->data)
            {
                IntNode* newVal = new IntNode(value);
                newVal->next = temp;
                current->next = newVal;
            }
            current = current->next;
        }
    }
}

void IntList::displayReverse(IntNode* curr) const{
    if(curr == 0){
        return;
    }
    if(curr==tail){
        cout<<curr->data;
        return;
    }
    else{
        displayReverse(curr->next);
        cout << " " <<curr->data;
        return;
    }
}

void IntList::displayReverse() const{
    displayReverse(head);
}