#include <iostream>
#include "Number.h"
using namespace std;

Number Number::operator++()
{
    num++;
    return *this;
}
Number Number::operator++(int)
{
    Number temp = *this;
    num++;
    return temp;
}
Number Number::operator--()
{
    num--;
    return *this;
}
Number Number::operator--(int)
{
    Number temp = *this;
    num--;
    return temp;
}
std::ostream &operator<<(std::ostream &os, const Number &c)
{
    os << c.getNum();
    return os;
}

int main(){

    Number n1(20);
    Number n2 = n1++;
    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;

    Number n3 = n2--;
    cout << "n2 = " << n2 << endl;
    cout << "n3 = " << n3 << endl;

    Number n4 = ++n3;
    cout << "n3 = " << n3 << endl;
    cout << "n4 = " << n4 << endl;

    Number n5 = --n4;
    cout << "n4 = " << n4 << endl;
    cout << "n5 = " << n5 << endl;
    return 0;
}