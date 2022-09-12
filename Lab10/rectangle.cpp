#include <iostream>
using namespace std;

class Rectangle
{
public: //如果生命为private,那在class外就没有办法使用
    double width;
    double height;

    double getArea()
    {
        return width * height;
    }
};

int main()
{
    Rectangle r;
    r.width = 1;
    r.height = 2;

    cout << "The width is: " << r.width << ", the height is :" << r.height << endl;
    cout << "The area is: " << r.getArea() << endl;

    return 0; 
}
