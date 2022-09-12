#include <iostream>
#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;

class complex
{
private:
    double real;
    double imag;

public:

    complex() : real(1), imag(1) { };
    complex(double re, double im)
    {
        real = re;
        imag = im;
    }

    complex operator+(const complex &rhs);
    complex operator+(double n);

    complex operator~();
    complex operator-(const complex &rhs);
    complex operator-(double n);

    complex operator*(const complex &rhs);
    complex operator*(double n);

    void operator!=(const complex &rhs);
    void operator==(const complex &rhs);
    
    ~complex();

    void show() const;

};


#endif