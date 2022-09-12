#include <iostream>
#include "rectangle.hpp"
using namespace std;

int main()
{
    Rectangle r1(4,40);   //默认的构造器，非明确的调用
    Rectangle r2(3.5,35.9); //明确的调用

    cout << "Rectangle 1" << endl;
    cout << "----------------" << endl;
    cout << "Width:     " << r1.getWidth() << endl;
    cout << "Height:    " << r1.getHeight() <<endl;
    cout << "Area:      " << r1.getArea() << endl;
    cout << "Perimeter: " << r1.getPerimeter() << endl;

    cout << "Rectangle 2" << endl;
    cout << "----------------" << endl;
    cout << "Width:     " << r2.getWidth() << endl;
    cout << "Height:    " << r2.getHeight() <<endl;
    cout << "Area:      " << r2.getArea() << endl;
    cout << "Perimeter: " << r2.getPerimeter() << endl;

    return 0;
}