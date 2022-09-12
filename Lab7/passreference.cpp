#include <iostream>
using namespace std;
/*x,y是reference type，就是真实变量的别名*/
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main()
{
    int val = 1024;
    int &refVal = val;  //refVal 就是val的另一个名字
    /*一旦初始化，这个引用变量就绑定初始目标， 不能再去refer另一个object
    对引用型的操作都是对绑定的object的操作*/
    
    int a = 45, b = 35;
    cout << "Before swap: " << endl;
    cout << "a = " << a << ", b = " << b << endl;

    swap(a,b);

    cout << "After swap: " << endl;
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}