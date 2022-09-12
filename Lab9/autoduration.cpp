#include <iostream>
using namespace std;

int main()
{
    int x = 30; // 最初始的x

    cout << "x in outer block: " << x << " at " << &x << endl;
    {
        int x = 77;
        cout << "x in inner block: " << x << " at " << &x << endl;
    }
    cout << "x in outer block: " << x << " at " << &x << endl;

    while(x++ < 33) //这里访问的x还是一开始的int x
    {
        int x = 100;
        x++;
        cout << "x in while loop: " << x << " at " << &x <<endl;
    }
    cout << "x in outer block: " << x << " at " << &x << endl;

    return 0;
}
