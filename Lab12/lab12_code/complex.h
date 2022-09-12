#include <iostream>
using namespace std;

class complex
{
private:
    double real;
    double imag;

public:
    complex() : real(1), imag(1) { };
    complex(double re, double im) : real(re),imag(im){ }
    complex(const complex& c); //copy constructor
    complex operator+ (const complex &c);
    friend ostream& operator << (ostream &os, const complex &c);
};
