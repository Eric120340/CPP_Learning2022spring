#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 2, c = 10;
    cout << "a > b?" << (a > b) << ", b > c? " << (b > c) << endl;
    cout << "Print the values of relational expressions as boolean formatting: " << endl;
    cout << boolalpha;// 0 - false, 1 - true
    cout << " a > b? " << (a > b) << ". b > c? " << (b > c) << endl;
    cout << "a * b == c? " << (a*b == c) << endl << endl;
    /*可以将算数结果转换为布尔值，0为false，非0为true*/
    cout << "b - a = " << (b-a) << ", its boolean value: " << (bool)(b-a) << endl;
    cout << "The value of (a = b/c) is:" << (a = b/c) << ", its boolean value: " << (bool)(a = b/c) << endl;

    cout << noboolalpha;
    cout << "a == b/c? " << (a == b/c) << boolalpha << ", print in logical value of (a == b/c): " << (a == b/c);
    return 0;
}