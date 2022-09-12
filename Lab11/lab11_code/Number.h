#include <iostream>
#ifndef NUMBER_H
#define NUMBER_H

using namespace std;

class Number
{
private:
    int number;
public:
    Number(){number = 0;};  //default constructor
    Number(int a){ number = a;}
    int getNum() const { return number; }

    Number operator ++();
    Number operator ++(int);
    Number operator --();
    Number operator --(int);
    ~Number();
};

 Number Number::operator ++()
    {
        number++;
        return *this;
    }
    Number Number::operator ++(int)
    {
        Number value = *this;
        value++;
        return value;
    }    

    Number Number::operator --()
    {
        number--;
        return *this;
    }

    Number Number::operator --(int)
    {
        Number value = *this;
        value--;
        return value;
    }    
ostream &operator<< (ostream &os, const Number &num)
{
        os << num.getNum();
        return os;
}

Number::~Number()
{
}


#endif