#include <iostream>
#include <string>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;


class Distance
{
    private:
        unsigned feet;
        double inches;
    public:
        Distance();
        Distance(unsigned,double);
        Distance(double);
        double convertToInches() const;
        const Distance operator+(const Distance &) const;
        const Distance operator-(const Distance &) const;
        void display() const;
    private:
        void init();
};