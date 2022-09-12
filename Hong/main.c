#include <stdio.h>
//#include "circle.c"
#include "circle.h"

int main()
{
    double result;
    result = circumference(3);
    printf("%f\n",result);    

    result = Area(3);
    printf("%f\n",result);
    return 0;
}