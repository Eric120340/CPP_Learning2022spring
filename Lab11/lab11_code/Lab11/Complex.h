#include <iostream>
class Complex
{
    private:
        double real;
        double imag;
    public:
    Complex() : real(1), imag(1) {}
    Complex(double r, double i) : real(r), imag(i) {}
    
    double getReal() const { return real; }
    double getImag() const { return imag; }

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator~() const;

    bool operator==(const Complex& c) const;
    bool operator!=(const Complex& c) const;

    friend Complex operator+(double n, const Complex& c);
    friend Complex operator*(const Complex& c,double n);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};
