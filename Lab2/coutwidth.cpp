#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << 56.8;

    cout.width(12);     //set the field width
    cout.fill('+');     //fill character to be used with justified field
    cout << 456.77 << endl << endl;

    cout.precision(2);  //set the precision of floating-point numbers
    cout << 123.356 << "\t";
    cout.precision(5);
    cout << 3897.678483 << endl;

    cout << fixed << 45.2 << endl;
    cout.unsetf(ios_base::fixed);       //cancel the setting which made by setf()
    return 0;
}