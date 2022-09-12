#ifndef CANDYBAR_H
#define CANDYBAR_H

#include <iostream>

using namespace std;
class CandyBar
{
public:
    char name[20];
    double weight;
    int cal;

    CandyBar(char n[20], double w, int c);
    ~CandyBar();
    void setCandyBar();
    void showCandyBar();
};


#endif