#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    double width;
    double height;

public:
    //默认构造器
    Rectangle();
    //带参数构造器
    Rectangle(double w, double h);

    //析构函数destructor
    ~Rectangle();
    
    double getArea();
    double getWidth();
    double getHeight();
    double getPerimeter();
    void setWidth(double w);
    void setHeight(double h);

};

#endif