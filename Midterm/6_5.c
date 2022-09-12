#include <stdio.h>

int main()
{
    int a,b,c;
    float sum1, sum2, sum3;
    float total;

    sum1 = sum2 = sum3 = 0;
    total = 0;
    scanf("%d %d %d",&a,&b,&c);
    for (int i = 0; i <= a; i++)
    {
        sum1 += i;
    }
    
    for (int i = 0; i <= b; i++)
    {
        sum2 += (i * i);
    }

    for (int i = 1; i <= c; i++)
    {
        sum3 += (1 / i);
    }
    
    total = sum1 + sum2 + sum3;
    printf("%f\n",total);
    
    return 0;
}