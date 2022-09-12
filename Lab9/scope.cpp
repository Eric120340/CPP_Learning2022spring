#include <iostream>
using namespace std;

int x = 128;
int main()
{
    int x = 256;
    cout << "local variable x = " << x << endl;
    cout << "global variable x = " << ::x << endl;
    //全局变量 用::来访问（scope-solution operator）
    return 0; 
}