#include <stdio.h>

int main()
{
    int N;
    float total = 0, a = 2.0, b = 1.0, temp = 0.0, val;
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        temp = a / b;
        total = total + temp;

        val = a;
        a += b;
        b = val;
    }
    printf("%.2f\n",total);
    return 0;
}