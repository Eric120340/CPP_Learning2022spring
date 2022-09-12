#include <iostream>
using namespace std;


inline double cube(double side)
{
    return side * side * side;
}

int main()
{
    double sideValue;
    cout << "Enter the side of your cube:";
    cin >> sideValue;

    cout << "Volume of cube with side " << sideValue << " is " << cube(sideValue) << endl;

    return 0; 
 }
