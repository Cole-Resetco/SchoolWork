#include <iostream>
#include <cstdlib>
#include "Music_collection.h"

using namespace std;

int main()
{
    Music_collection m;
    Music_collection q;
    string n = "hello";
    string p = "a";
    string o = "d";
    Tune A(n);
    Tune B(p);
    Tune C(o);
    m.add_tune(A);
    m.add_tune(B);
    m.add_tune(C);
    cout << m;
    cout << "first array" << endl;

    string a = "bye";
    string b = "b";
    string c = "c";
    Tune D(a);
    Tune E(b);
    Tune F(c);
    q.add_tune(D);
    q.add_tune(E);
    q.add_tune(F);
    cout << q;
    
    cout << "second array" << endl;
    
    cout << "initiating copy constructor" << endl;
    
    Music_collection g(q);
    
    cout << g;
    
}
