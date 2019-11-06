#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int f(const string& s)
{
    if (s.size() < 2) return 0;
    if (s.at(0) == s.at(1)) return 1 + f(s.substr(1));
    return f(s.substr(1));
}

int main()
{
   cout << f("tweedleddeee");
    
    return 0;
}