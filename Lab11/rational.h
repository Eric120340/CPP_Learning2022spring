#include <iostream>
#pragma once

using namespace std;

class rational
{
private:
    int numerator;
    int denominator;

public:
    rational(int n = 0, int d = 1) : numerator(n) , denominator(d) { };
    ~rational();

    int getN() const
    {
        return numerator;
    }

    int getD() const
    {
        return denominator;
    }

    void show() const
    {
        cout << numerator << "/" << denominator << endl;
    }
};

