#include <stdio.h>

int rerange(int a, int b)
{
    int temp;
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    printf("%d %d\n",a,b);
    return 0;
}
int main()
{
    int a, b;
    printf("Input 2 number:\n");
    scanf("%d %d", &a, &b);
    rerange(a, b);
    printf("%d %d\n", a, b);
    return 0;
}
