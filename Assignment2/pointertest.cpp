#include <iostream>
using namespace std;

int main()
{
    int a = 8;
    int *father = NULL;
    father = &a;

    cout << *father << endl;
    cout << father << endl; //指针指向的值的地址
    cout << &father << endl;//指针地址
    if (!father)
    {
        cout << "This is a NULL pointer" << endl;
    }
    else
        cout << "This is not a NULL pointer" << endl;
    return 0;
}