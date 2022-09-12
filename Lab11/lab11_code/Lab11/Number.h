#include <iostream>
class Number
{
private:
    int num;

public:
    Number() : num(0) {}
    Number(int n) : num(n) {}
    int getNum() const { return num; }
    Number operator++();
    Number operator++(int);
    Number operator--();
    Number operator--(int);
};