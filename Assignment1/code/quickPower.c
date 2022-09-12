#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include "assign1_mat.h"
#include "assign1_mat.c"
int quick_power(int x, int n);

int fast_Power(int x, int n); 
//using namespace std;
 
/**
 * 普通的求幂函数
 * @param base 底数
 * @param power  指数
 * @return  求幂结果的最后3位数表示的整数
 */
int main() 
{
    clock_t start, finish;
    //clock_t为CPU时钟计时单元数
    int base, power;
    base = 959465599;
    power = 478516499;
    start = clock();
    //clock()函数返回此时CPU时钟计时单元数
    printf("base: %d, power: %d\nanswer: %d\n",base,power,fast_Power(base,power));
    finish = clock();
    //clock()函数返回此时CPU时钟计时单元数
    printf("time: %f\n",(double)(finish - start) / CLOCKS_PER_SEC);
    //finish与start的差值即为程序运行花费的CPU时钟单元数量，再除每秒CPU有多少个时钟单元，即为程序耗时
    return 0;
 
}

int fast_Power(int x, int n) 
{
    unsigned long long answer = 1;
    long long x1 = x % MODULO;
    long long n1 = n;
    while (n1 > 0) {
        if (n1 & 1) {//此处等价于if(n%2==1)
            answer = (answer * x1) % MODULO;
        }
        n1 >>= 1;//此处等价于n=n/2
        x1 = ((x1%MODULO) * (x1%MODULO)) % MODULO;
    }
    return answer;
}

//Task1 20pts
//Power of x^n
/* int quick_power_recursion(int x, int n)
{
    if(n == 0)
    {
        return 1;
    }
    int partition_factor = quick_power_recursion(x,floor(n/2));
    if(n%2 != 0)
    {
        return partition_factor * partition_factor * x;
    }else{
        return partition_factor * partition_factor;
    }
}
 */
int quick_power(int x, int n)
{
    unsigned long long answer = 1;
    long long x1 = x % MODULO;
    long long n1 = n;

    for(;n1 != 0; n1 /= 2)
    {
        if(n1%2 == 1)
        {  
            answer = (answer * x1) % MODULO;
        }
        x1 = ((x1 % MODULO) * (x1 % MODULO)) % MODULO;
    }
    return answer;
}
/* 
int main(void)
{
    printf("快速幂(递归算法):%d\n",quick_power_recursion(10,9));
    printf("快速幂(非递归):  %d\n",quick_Power(2,33));
    return 0;
} */