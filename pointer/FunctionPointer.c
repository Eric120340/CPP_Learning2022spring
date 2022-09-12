#include <stdio.h>

void output(void);  //output声明

int main(void)
{
    void (*p_output)();//指向函数的指针变量，类型是void没有返回值
    p_output = output;  //指针变量的初始化——赋值，p_output指向函数output
    (*p_output)();
    return 0;
}
void output(void)
{
    printf(" Love dbq! \n");
}