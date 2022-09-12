#include <iostream>
#include "Complex.h"
using namespace std;

Complex Complex::operator+(const Complex &c) const
{
    Complex result;
    result.real = real + c.real;
    result.imag = imag + c.imag;
    return result;
}
Complex operator+(double n, const Complex &c)
{
    double real = n + c.real;
    double imag = c.imag;
    return Complex(real, imag);
}
Complex Complex::operator-(const Complex &c) const
{
    Complex result;
    result.real = real - c.real;
    result.imag = imag - c.imag;
    return result;
}
Complex operator-(const Complex &c, double n)
{
    double real = c.getReal() - n;
    double imag = c.getImag();
    return Complex(real, imag);
}
Complex Complex::operator*(const Complex &c) const
{
    Complex result;
    result.real = real * c.real - imag * c.imag;
    result.imag = real * c.imag + imag * c.real;
    return result;
}
Complex operator*(double n, const Complex &c)
{
    double real = n * c.getReal();
    double imag = n * c.getImag();
    return Complex(real, imag);
}
Complex Complex::operator~() const
{
    Complex result;
    result.real = real;
    result.imag = -imag;
    return result;
}
bool Complex::operator==(const Complex &c) const
{
    return real == c.real && imag == c.imag;
}
bool Complex::operator!=(const Complex &c) const
{
    return real != c.real || imag != c.imag;
}
std::ostream &operator<<(std::ostream &os, const Complex &c)
{
    os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
    return os;
}

std::istream &operator>>(std::istream &is, Complex &c)
{
    is >> c.real >> c.imag;
    return is;
}
int main()
{
    Complex a(3.0, 4.0);
    Complex b(2.0, 6.0);

    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "~b is " << ~b << endl;
    cout << "a + b is " << a + b << endl;
    cout << "a - b is " << a - b << endl;
    cout << "a - 2 is " << a - 2 << endl;
    cout << "a * b is " << a * b << endl;
    cout << "2 * a is " << 2 * a << endl;

    Complex c = b;
    cout << "b == c is " << (b == c) << endl;
    cout << "b != c is " << (b != c) << endl;
    cout << "a ==c is " << (a == c) << endl;

    Complex d;
    cout << "Enter a complex number:" << endl;
    cin >> d;
    cout << "d is " << d << endl;
    return 0;
}