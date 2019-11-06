#include <iostream>

using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    
    cout <<arr[2] <<endl;
    cout << *(arr + 2) << endl;
    
    cout << arr << endl;
    cout << *arr << endl;
    
    int *iptr = arr;  // you cannot do *iptr = arr[2]; because not same type
    cout << *iptr << endl;
    cout << iptr[2] << endl; // also dereferences, but at specified point
    cout << *(iptr + 2) << endl; //moves iptr address 2 slots over * try not to use
    cout << *iptr + 2 << endl; // adds 2 to iptr value * try not to use
    //                                                      |              
    int *arr2 = new int[4]; //                              |
    for (int i = 0; i < 4; i++) // use this instead  <-------
    {
        arr2[i] = i * 3; // allocates the dynamicaly allocated array in heap with 0 3 6 9
    }
    
    delete arr2; //deletes the first value of the heap array that arr2 is pointing at * causes memory leaks
    delete []arr2; // deletes the whole dynamicaly allocated array
    
    /* being able to do assignment 5, or specificaly the pushing back in heap 
    of the array is going to probably be on the midterm and final
    */
    
    
    
    
    return 0;
}