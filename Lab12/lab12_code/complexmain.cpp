#include <iostream>
#include "complex.h"
using namespace std;

complex::complex(const complex &c)
{
    real = c.real;
    imag = c.imag;
    cout << "Copy Constructor called." << endl;
}

complex complex::operator+(const complex &c)
{
    complex result;
    result.real = this->real + c.real;
    result.imag = this->imag + c.imag;
    return result;
}
ostream &operator<<(ostream &os, const complex &c)
{
    os << c.real << (c.imag >= 0 ? " + " : "") << c.imag << "i";
    return os;
}

int main()
{
    complex c1(1, 2);
    complex c2(c1);

    cout << c1 << endl;
    cout << c2 << endl;
    complex c3 = c1;
    c3 = c1 + c2;
    cout << c3 << endl;
    
    return 0;
}