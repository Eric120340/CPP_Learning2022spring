#include <iostream>
using namespace std;

struct demo
{
    int a;
};

int main()
{
    int x = 5;
    int y = 6;
    demo d;

    int *p;
    p = &x; //pointer 重新初始化
    p = &y;

    int  &r = x;
    r = y; // x values become 6

    p = NULL;
    p++;    //points to next memory location
    r++;    //x value become 7

    cout << &p << " " << &x << endl;    //Different address
    cout << &r << " " << &x << endl;    //Same address

    demo *q = &d;   //pointer
    demo &qq = d;   //reference
    q->a = 8;
    qq.a = 8;
    cout << p << endl;
    cout << r << endl;

    const int ci = 100;
    const int &r0 = ci;
    cout << r0 << endl;

    int i = 42;
    int &r1 = i;
    const int &r2 = i;
    const int &r3 = 99;
    const int &r4 = r1 * 2;
    //int &r5 = r1 * 3; r5不是const 类型
    r1 = 0;
    //r2 = 5;   r2不是const类型
    return 0;
}
