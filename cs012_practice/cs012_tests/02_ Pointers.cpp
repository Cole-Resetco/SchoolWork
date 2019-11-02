#include <iostream>

using namespace std;


int main()
{
    int n = 10
    int r1, r2;
    int *ptr1;
    double x = 3.5;
    
    cout << n << endl; //cout n value
    cout << &n << endl; // cout the address of n (location)
    cout << x << endl; // cout the x value
    cout << &x << endl; // cout the address of x (location)
    
    /*
       when it outpust the location it will look something like:
        0x7fffda1435d4
       which has to with the binary operators associated with it
       eg: (0111 = 7)(1111 = f)
    */
    
    int *iptr = &n //will store the address of n to the pointer
    double *dptr = &x // will try to store an int adress to a double pointer 
                      // and will not work
                      
    cout << iptr << endl; // will cout the address
    cout << dptr << endl;
    
    /* pointers initialized to an address (no *), store the actual address as 
    its value
    */
    
    cout << *iptr << endl; //* -dereference operators; will cout value 
    cout << *dptr << endl;
    
    //int *ptr1, ptr2 will declare 1 pointer and 1 int, use *ptr1, *ptr2
    
    
    int *iptr = new int(5);// new gives a location in memory that is not named
                           // (dynamic allocation of memory)
                           // the pointer points to this unnamed value
                           // this is called  dynamic allocation
    double *dptr = new double(1.2);
    
    /* with pointers pointing to no name memory locations, we now have two
    major chuncks of memory we must think about: runtime stack: where named 
    variables and pointers are, and Heap(freestore): where unnamed intergers
    (and probably other things) are stored ---> the heap addresses are much 
    smaller than runtime stack addresses
    */
    
    /*
    Going out of scope automatically deallocates in runtime stack
    heap does not deallocate, use delete dptr or itpr
    */
    
    
    //SegFall is abbrv for Segmentation Fall
    // trying to access a segment of memory that is not there
    delete iptr;
    delete dptr;
    // iptr and dptr are now dangling pointers
    /*
    
    KNOW THESE TERMS
    __________________________
    1. Dangling pointer: 
    --Def: A pointer that's no longer used
    --to reallocate memory to a dangling pointer:
        -iptr = 0 or iptr = new int(5)
    
    */
    
    /* if the local function is deleted, it deletes the runtime stack location
    but not the heap memory causing memory leaks. make sure to DELETE heap segments
    
    return 0;
    
    
}