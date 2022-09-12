#include <iostream>
using namespace std;

class Rectangle
{
private: 
    double width = 1;
    double height = 2;
public:
    double getArea()
    {
        return width * height;
    }
    double getWidth()
    {
        return width;
    }

    double getHeight()
    {
        return height;
    }

    void setWidth(double w)
    {
        width = w;
    }
    
    void setHeight(double h)
    {
        height = h;
    }
};

int main()
{
    Rectangle r;
    cout << "The width is: " << r.getWidth()
         << ", the height is:" << r.getHeight() << endl;
    cout << "The area is: " << r.getArea() << endl;

    return 0;
}
