#include <iostream>
#include "CandyBar.h"
using namespace std;


CandyBar::CandyBar(char n[20],double w, int c)
{
    weight = w;
    cal = 230;
}

CandyBar::~CandyBar()
{
    std::cout << "Destructor is called." << std::endl;
}

void CandyBar::setCandyBar()
{
    cout << "Enter brand name of a candybar:" << "Bulle Marphi" << endl;
    cout << "Enter weight of the candybar:" << weight << endl;
    cout << "Enter calories(an integer) in the candybar:" << cal << endl;
}

void CandyBar::showCandyBar()
{
    cout << "Brand: " << "Bulle Marphi" << endl;
    cout << "Weight: " << weight << endl;
    cout << "Calories: " << cal << endl;

}