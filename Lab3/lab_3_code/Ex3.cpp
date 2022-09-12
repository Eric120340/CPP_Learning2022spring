#include <iostream>
using namespace std;

struct CandyBar
{
    char name[21];
    float weight;
    int calories; 
};

int main()
{
    CandyBar CandyBar1, CandyBar2, CandyBar3;
    

    cout << "Please input three CandyBar's information: " << endl;
    cout << "Enter the brand name of candy bar: ";
    cin.get(CandyBar1.name,20);
    cout << "Enter the weight: ";
    cin >> CandyBar1.weight;
    cout << "Enter the calories: ";
    cin >> CandyBar1.calories;
    cin.get();

    cout << "Enter the brand name of candy bar: ";
    cin.get(CandyBar2.name,20);
    cout << "Enter the weight: ";
    cin >> CandyBar2.weight;
    cout << "Enter the calories: ";
    cin >> CandyBar2.calories;
    cin.get();

    cout << "Enter the brand name of candy bar: ";
    cin.get(CandyBar3.name,20);
    cout << "Enter the weight: ";
    cin >> CandyBar3.weight;
    cout << "Enter the calories: ";
    cin >> CandyBar3.calories;
    cin.get();

    cout << "\nDisplay the CandyBar array contents" << endl;

    cout << "Brand name: " << CandyBar1.name << endl;
    cout << "Weight: " << CandyBar1.weight << endl;
    cout << "Canlories: " << CandyBar1.calories << endl;

    cout << "Brand name: " << CandyBar2.name << endl;
    cout << "Weight: " << CandyBar2.weight << endl;
    cout << "Canlories: " << CandyBar2.calories << endl;

    cout << "Brand name: " << CandyBar2.name << endl;
    cout << "Weight: " << CandyBar2.weight << endl;
    cout << "Canlories: " << CandyBar2.calories << endl;
    return 0;

}