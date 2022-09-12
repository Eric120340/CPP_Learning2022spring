#include <stdio.h>

long fac(int n)
{
    long m;
    if (n == 1)
        m = 1;
    else
        m = fac(n-1) * n;
    return m;
}

int main()
{
    int n;
    float m;
    printf("Input the value of n.\n");
    scanf("%d",&n);
    printf("%d! = %ld\n",n,fac(n));
    return 0;
}
