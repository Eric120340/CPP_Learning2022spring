#include <iostream>
#include "complex.h"


complex::~complex()
{
    cout << " DEC Called" << endl;
}

complex complex::operator+(const complex &rhs)
{
    complex result;
    result.real = real + rhs.real;
    result.imag = imag + rhs.imag;

    return result;
}

complex complex::operator+(double n)
{
    complex result;
    result.real += this->real + n;
    result.imag += this->imag;
    return result;
}

complex complex::operator~()
{
    complex result;
    result.real = this->real;
    result.imag = -this->imag;
    return result;
}

complex complex::operator-(const complex &rhs)
{
    complex result;
    result.real = real - rhs.real;
    result.imag = imag - rhs.imag;

    return result;
}
complex complex::operator-(double n)
{
    complex result;
    result.real = this->real - n;
    result.imag = this->imag;
    return result;
}

complex complex::operator*(const complex &rhs)
{
    complex result;
    result.real = (this->real * rhs.real) - (this->imag * rhs.imag); 
    result.imag = (this->real * rhs.imag) + (this->imag * rhs.real);

    return result;    
}

complex complex::operator*(double n)
{
    complex result;
    result.real = this->real * n;
    result.imag = this->imag * n;
    return result;
}

void complex::operator!=(const complex &rhs)
{
    bool result;
    if (this->real != rhs.real || this->imag != rhs.imag)
    {
        result = 1;
    }
    else
        result = 0;
        
    if (result == 1)
    {
        cout << "true";
    }
    else
        cout << "false";
}
void complex::operator==(const complex &rhs)
{
    bool result;
    if (this->real == rhs.real && this->imag == rhs.imag)
    {
        result = 1;
    }
    else
        result = 0;
    if (result == 1)
    {
        cout << "true";
    }
    else
        cout << "false";
    
}

void complex::show() const
{
    cout << real << (imag >= 0? "+":"") << imag << "i";
}
