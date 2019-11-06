#include <iostream>
#include "Distance.h"
#include <string>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    Distance d1;
    cout << "d1:";
    d1.display();
    cout<<endl;
    Distance d2= Distance(2,5.9);
    Distance d3= Distance(3.75);
    Distance d3a= Distance(60.75);
    cout << "d2:";
    d2.display();
    cout << endl;
    cout << "d3a:";
    d3a.display();
    cout << endl;
    cout << "d3:";
    d3.display();
    cout << endl;
    
    //testinithelperfunction
    Distance d4 = Distance(5,19.34);
    Distance d5 = Distance(100);
    cout << "d4:" ; d4.display(); cout << endl;
    cout << "d5:" ; d5.display(); cout << endl;

    //testadd(<12inches)
    cout << "d4+d5:"; (d4+d5).display(); cout << endl;

    //testadd(>12inches)
    cout << "d2+d4:"; (d2+d4).display(); cout << endl;

    //testsub(0ft)
    cout << "d3‐d1:"; (d3-d1).display(); cout << endl;

    //testsub(0ft,negativeconversion)
    cout << "d1‐d3:"; (d1-d3).display(); cout << endl;

    //testsub(positiveft&inch)
    cout << "d4‐d2:"; (d4-d2).display(); cout << endl;

    //testsub(negativeft&inch)
    cout << "d2‐d4:"; (d2-d4).display(); cout << endl;
    
    //testsub(negativeft,positiveinch)
    cout << "d4‐d5:"; (d4-d5).display(); cout << endl;

    //testsub(positiveft,negativeinch)
    cout << "d5‐d2:"; (d5-d2).display(); cout << endl;
    
    return 0;
}