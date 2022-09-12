#include <iostream>
#include "candybar.h"
using namespace std;


void setCandyBar(CandyBar & cb)
{
    cout << "Call the set function of Passing by reference:" << endl;
    cout << "Enter brand name of a Candy bar: ";
    cin.getline(cb.brand,30);
    cout << "Enter weight of the Candy Bar:";
    cin >> cb.weight;
    cout << "Enter calories(an integer value) in the Candy bar:";
    cin >> cb.calorie;
    cout << '\n';
}

void setCandyBar(CandyBar * cb)
{
    cin.get();
    cout << "Call the set function of Passing by pointer:" << endl;
    cout << "Enter brand name of a Candy bar: ";
    cin.getline(cb->brand,30);
    cout << "Enter weight of the Candy Bar:";
    cin >> cb->weight;
    cout << "Enter calories(an integer value) in the Candy bar:";
    cin >> cb->calorie;    

    cout << '\n';
}

void showCandyBar(const CandyBar & cb)
{
    cout << "Call the show function of Passing by reference:" << endl;
    cout << "Brand: " << cb.brand << endl;
    cout << "Weight: " << cb.weight << endl;
    cout << "Calories: " << cb.calorie << endl;
    cout << '\n';

}

void showCandyBar(const CandyBar * cb)
{
    cout << "Call the show function of Passing by pointer:" << endl;
    cout << "Brand: " << cb->brand << endl;
    cout << "Weight: " << cb->weight << endl;
    cout << "Calories: " << cb->calorie << endl;
    cout << '\n';
}

