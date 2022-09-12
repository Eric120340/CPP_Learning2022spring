#include <iostream>
using namespace std;

struct CandyBar
{
    char name[20];
    float weight;
    int calories; 
};

int main()
{
    CandyBar Candy;
    cout << "Enter the brand name of candy bar: ";
    cin.get(Candy.name,20);
    cout << "Enter the weight: ";
    cin >> Candy.weight;
    cout << "Enter the calories: ";
    cin >> Candy.calories;

    cout << "Brand: " << Candy.name << endl;
    cout << "Weight: " << Candy.weight << endl;
    cout << "Calories: " << Candy.calories << endl;
    return 0;
}