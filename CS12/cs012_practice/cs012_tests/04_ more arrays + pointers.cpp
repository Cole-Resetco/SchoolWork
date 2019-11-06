#include <iostream>

using namespace std;

int main()
{
    int *iptr = 0, *jptr = 0, *arr_ptr = 0;
    iptr = new int(10);
    arr_ptr = new int[5];
    /* this creaes 3 pointers, sets 1 to a memory in heap with value 10
    // and sets the arr_ptr too an array in heap with 5 memory slots
    */
    
    
    
    for (int i = 0; i < 4; ++i)
    {
        arr_ptr[i] = i;
    }
    /* fills the heap vector with values 0 1 2 3 in there respective
    // indexs while index 4 (the fifth slot) remains garbage
    */
    
    
    jptr = &arr_ptr[2];
    cout << arr_ptr << ' ' << jptr << endl; // couts 2 addresses
    cout << *arr_ptr << ' ' <<  *jptr << endl; // couts 0 and 2
    cout << arr_ptr[1] << ' ' << jptr[1] << endl; // couts 1 and 3
    // !!!!! important ---- jptr[1] is the same as *(jptr + 1) 
    // it dereferences the pointer and adds 1, same with any other number
    // [3] = +3 [6] = +6
    
    //endl; flushes out the buffer( what does this do?) 
    
    
    delete[] arr_ptr; // deletes the heap values, arr_ptr and jptr are now dangling
    cout << arr_ptr << ' ' << jptr << ' ' << *jptr << endl;
    // dereferencing a dangling pointer with give UNDEFIEND BEHAVIOR
    // can cause crashes 
    return 0;
    
    
    //midterm - pointers, dynamic memory allocation, assignment 6
}