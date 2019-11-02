#include <iostream>

using namespace std;

int main()
{
    // size and capacity are different in vectors. size referes to the 
    //size of the vector, but in dynamic alocation, we can dynamicaly
    //allocate an array in a vector, with a set capacity.
    
    //3 data fields - size = 0, capacity = 0, data = 0 (default)
    
    
    IntVector v(3,5); //constructs a vector with size 3, an array with 
    //    capacity 3, and data values 5. (vector representation)[5][5][5]
    
    //const is an accessor function, its not allowed to change
    
    v.at(2) = 10; //passing in by reference, return by reference is possible
}