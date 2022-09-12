#include <iostream>
using namespace std;

int main()
{
    int x,y;
    cout << "Input the value of x and y" << endl;
    cin >> x;
    cin >> y;
    cout << "Result" << endl;
    cout << "x value y value Expressions    Result" << endl;
    cout << x << " |    " << y << " |     " << "x=y+3" <<"          |x=" << y+3 << endl;
    cout << x << " |    " << y << " |     " << "x=y-2" <<"          |x=" << y-2 << endl;
    cout << x << " |    " << y << " |     " << "x=y*5" <<"          |x=" << y*5 << endl;
    cout << x << " |    " << y << " |     " << "x=x/y" <<"          |x=" << x/y << endl;
    cout << x << " |    " << y << " |     " << "x=x%y" <<"          |x=" << x%y << endl;
    return 0;

}