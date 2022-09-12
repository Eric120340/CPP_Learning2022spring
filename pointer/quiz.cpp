#include <iostream>
using namespace std;


int main(void)
{
    short sam = 32766;
    sam += +2;
    cout << sam << endl;

    float a = 2.34E+15f;
    float b = a + 100.0f;
    cout << b-a << endl;


    signed char c1 = 127;
    signed char c2 = 1;
    int csum = c1 + c2;
    cout << csum << endl;


    int c = 124;
    float d = 3.0;
    cout << c+d << endl;
    
    int e = 2;
    char f = '3';
    cout << e + (f-'0') << endl;

    float logs = 121.0 / 4.0 * 5.0;
    cout << logs << endl;    
}