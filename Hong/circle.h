#include <stdio.h>

struct point 
{
    int x;
    int y;
};

#define PI 3.14

/*计算圆周长*/
double circumference(int radius);
/*计算圆的面积*/
double Area(int radius);
/*画圆*/
void Paint(struct point center, int radius);


