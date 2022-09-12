#include <stdio.h>

int main(void)
{
    short sam = 32766;
    sam += +2;
    printf("%d\n",sam);

    float a = 2.34E+15f;
    float b = a + 100.0f;
    printf("%f\n",b-a);

    signed char c1 = 127;
    signed char c2 = 1;
    int csum = c1 + c2;
    printf("%d\n",csum);

    int a = 124;
    float b = 3.0;
    println(a+b);
    
}