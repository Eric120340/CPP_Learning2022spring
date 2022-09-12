#include <stdio.h>

int main()

{
    int input = 0;
    int data, factor, sum; /* data表示要判断的数，fator表示因子，sum表示因子之和*/

    scanf("%d", &input);
    for (data = 2; data <= 1000; data++)
    {

        // 1是所有整数的因子，所以因子之和从1开始

        sum = 1;

        for (factor = 2; factor <= data / 2; factor++)

        {

            /* 判断data能否被fator整除，能的话fator即为因子 因子不包括自身 */

            if (data % factor == 0)

            {

                sum += factor;
            }
        }

        // 判断此数是否等于因子之和 */

        if (sum == data)

        {

            printf("%d its factors are 1, ", data);

            for (factor = 2; factor <= data / 2; factor++)

            {

                if (data % factor == 0)

                {

                    printf("%d, ", factor);
                }
            }

            printf("\n");
        }
    }

    return 0;
}
