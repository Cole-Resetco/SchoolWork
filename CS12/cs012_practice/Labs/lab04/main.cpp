#include <iostream>
#include <vector>

using namespace std;

class Rational
{
   private:
      int numer;
      int denom; 
   public:
      Rational();
      Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const; 
      void display() const; 
};
Rational::Rational()
{
    numer = 0;
    denom = 1;
}
Rational::Rational(int a)
{
    numer = a;
    denom = 1;

}
Rational::Rational(int a, int b)
{
    numer = a;
    denom = b;
}
const Rational Rational::add(const Rational &b) const
{
    Rational a;
    a.numer = (numer*b.denom + denom*b.numer) ;
    a.denom = (denom*b.denom); 
    return a;
    
}
const Rational Rational::subtract(const Rational &b) const
{
    Rational a;
    a.numer = (numer*b.denom - denom*b.numer) ;
    a.denom = (denom*b.denom); 
    return a;
    
}
const Rational Rational::multiply(const Rational &b) const
{
    Rational a;
    a.numer = (numer*b.numer) ;
    a.denom = (denom*b.denom); 
    return a;
    
}
const Rational Rational::divide(const Rational &b) const
{
    Rational a;
    a.numer = (numer*b.denom) ;
    a.denom = (denom*b.numer); 
    return a;
    
}
void Rational::display() const
{
    cout << numer << '/' << denom ;
}

int main(){
 Rational r;
 r.display();
}

Rational rat1(2, 3);
Rational rat2(2);
Rational rat3 = rat1.add(rat2);
rat3.display();