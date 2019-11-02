#include <iostream>
#include <cstdlib>

using namespace std;

void reverse (string &s)
{
    
    if(s.size() == 0)
    {
        return;
    }
    else
    {
        //cout << "starting recurstion" << endl;
        //cout << "this is the string: " << s << ", this is the size: " << s.size() << endl;
        cout << s.at(s.size() - 1);
        s = s.substr(0, s.size() - 1);
        reverse(s);

        return;
    }
    return;
    
}

int main()
{
    string s;
    s = "Test String";
    reverse(s);
}