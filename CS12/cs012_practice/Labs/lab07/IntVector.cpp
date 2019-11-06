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
#include "IntVector.h"
#include <cstdlib>

using namespace std;

IntVector::IntVector()
{
    sz = 0;
    cap = 0;
    data  = 0;
}

IntVector::IntVector(unsigned size)
{
    sz = size;
    cap = size;
    data = new int[size];
    for (unsigned i = 0; i < size; ++i)
    {
        data[i] = 0;
    }
    
}

IntVector::IntVector(unsigned size, int value)
{
    sz = size;
    cap = size;
    data = new int[size];
    for (unsigned i = 0; i < size; ++i)
    {
        data[i] = value;
    }
}

IntVector::~IntVector()
{
    delete[]data;
    data = 0;
}

unsigned IntVector::size() const
{
    return sz;
}

unsigned IntVector::capacity() const
{
    return cap;
}

bool IntVector::empty() const
{
    if(sz == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const int & IntVector::at(unsigned index) const
{
    if(index > sz)
    {
        exit(1);
    }
    return data[index];
}

int & IntVector::at(unsigned index)
{
     if(index > sz)
    {
        exit(1);
    }
    return data[index];
}

const int & IntVector::front() const
{
    return data[0];
}

int & IntVector::front() 
{
    return data[0];
}

const int & IntVector::back() const
{
    return data[sz - 1];
}

int & IntVector::back()
{
    return data[sz - 1];
}

void IntVector::expand()
{
    //cout << "The current cap of the vector is: " << cap << " and size: " 
         //<< sz << endl;
    unsigned tempcap = cap;
    cap = (cap * 2);
    int *tempdata;
    tempdata = new int[cap];
    for (unsigned i = 0; i < cap; ++i)
    {
        tempdata[i] = 0;
    }
    for(unsigned i = 0; i < tempcap; ++i)
    {
        tempdata[i] = data[i];
    }
    delete[]data;
    data = tempdata;
    //Create new array of size cap
    //Copy from data_old to data_new
    //Set data = data_new
    
}

void IntVector::expand(unsigned amount)
{
    //cout << "The current cap of the vector is: " << cap << " and size: " 
         //<< sz << endl;
    cap = (cap + amount);
    int *tempdata;
    tempdata = new int[cap];
    for (unsigned i = 0; i < cap; ++i)
    {
        tempdata[i] = 0;
    }
    for(unsigned i = 0; i < sz; ++i)
    {
        tempdata[i] = data[i];
    }
    delete[]data;
    data = tempdata;
    //Create new array of size cap
    //Copy from data_old to data_new
    //Set data = data_new
    
}

void IntVector::insert(unsigned index, int value)
{
    if(index >= sz)
    {
        exit(1);
    }
    ++sz;
    
    if(sz > cap)
    {
        expand();
    }
    
    int *tempdata;
    tempdata = new int[cap];
    
    for(unsigned i = 0; i < index; i++)
    {
        tempdata[i] = data[i];
    }
    for(unsigned j = index; j < sz; ++j)
    {
        tempdata[j+1] = data[j];
        
    }
    tempdata[index] = value;
    delete[]data;
    data = tempdata;

    
    
}

void IntVector::erase(unsigned index)
{
    if(index >= sz)
    {
        exit(1);
    }

     int *tempdata;
    tempdata = new int[cap];
    
    for(unsigned i = 0; i < index; i++)
    {
        tempdata[i] = data[i];
    }
    for(unsigned j = index; j < sz; ++j)
    {
        tempdata[j] = data[j+1];
    }
    delete[]data;
    data = tempdata;
    --sz;


    
    
}

void IntVector::push_back(int value)
{
    if(cap == 0)
    {
        expand(1);
    }
    
    else if((sz + 1) > cap)
    {
        expand();
    }
    this->data[sz] = value;
    ++sz;
    
    
}

void IntVector::pop_back()
{
    if(empty())
    {
        exit(1);
    }
    --sz;

}

void IntVector::clear()
{
    sz = 0;
}

void IntVector::assign(unsigned n, int value)
{
    sz = n;
    if( sz > cap)
    {
        if((cap * 2) < n)
        {
            expand(n - cap);
        }
        else
        {
            expand();
        }
        
    }
    for(unsigned i = 0; i < sz; ++i)
    {
        data[i] = value;
    }

}

void IntVector::resize(unsigned size)
{
    
    if(size <= sz)
    {
        sz = size;
    }
    if(size > sz)
     {
         if(sz > cap)
        {
            if(sz > (cap * 2))
            {
                expand(size - sz);
            }
            else
            {
                expand();
            }
        }
        unsigned tempsz = sz;
        sz += size - sz;
        
        for(unsigned i = tempsz; i < sz; ++i)
        {
            data[i] = 0;
        }
    }

}

void IntVector::resize(unsigned size, int value)
{

    if(size <= sz)
    {
        sz = size;
    }
    if(size > sz)
    {
        if(sz > cap)
        {
            if(sz > (cap * 2))
            {
                expand(size - sz);
            }
            else
            {
                expand();
            }
        }
        unsigned tempsz = sz;
        sz += size - sz;
        
        for(unsigned i = tempsz; i < sz; ++i)
        {
            data[i] = value;
        }
    }

}

void IntVector::reserve(unsigned n)
{
    if (cap < n)
    {
        expand(n - cap);
    }
}