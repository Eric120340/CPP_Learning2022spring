#include <stdio.h>
int main()
{
    int N, a[20], b[20], i, j, k, p;
    scanf("%d", &N);
    i = 1;
    while (i <= N)
    {
        scanf("%d%d", &a[i], &b[i]);
        i++;
    }
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= b[i]; j++)
        {
            for (k = 1; k < a[i]; k++)
            {
                for (p = 1; p <= a[i]; p++)
                {
                    if (p == k || p + k == a[i] + 1)
                        printf("X");
                    else
                        printf(" ");
                }
                printf("\n");
            }
        }
        for (j = 1; j <= a[i]; j++)
        {
            if (j == k || j + k == a[i] + 1)
                printf("X");
            else
                printf(" ");
        }
        printf("\n");
        if (i != N)
            printf("\n");
    }
    return 0;
}
