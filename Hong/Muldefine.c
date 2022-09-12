#include <stdio.h>
#define add(a, b, c, result) \
    result = a + b;          \
    result += c;

int main()
{
    int sum;

    add(1, 2, 3, sum);
    printf("sum = %d\n", sum);

    return 0;
}