#include <iostream>
#include "rectangle.hpp"

Rectangle::Rectangle()
{
    width = 1;
    height = 2;
}

Rectangle::Rectangle(double w, double h)
{
    width = w;
    height = h;
}

//没当析构函数被调用
Rectangle::~Rectangle()
{
    std::cout << "Destructor is called." << std::endl;
}

double Rectangle::getArea()
{
    return width * height;
}

double Rectangle::getWidth()
{
    return width;
}

double Rectangle::getHeight()
{
    return height;
}

double Rectangle::getPerimeter()
{
    return 2 * (width + height);
}

void Rectangle::setWidth(double w)
{
    width = w;
}

void Rectangle::setHeight(double h)
{
    height = h;
}