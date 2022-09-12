#include <stdio.h>

int main()
{
    long long a;
    scanf("%lld", &a);
    int i = 1;
    long long total = 0;
    for (i = 1; i <= a; ++i)
    {
        int b = 0;
        long long sum = 1;
        for (b = i; b > 0; b = b - 1)
        {
            sum = sum * b;
        }
        total = total + sum;
    }
    printf("%lld", total);
    return 0;
}