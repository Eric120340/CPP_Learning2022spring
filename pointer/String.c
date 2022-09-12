#include <stdio.h>

int main(void)
{
    char ver[] = "Gate Ver1.00 20100427";
    char *p_ver;
    char *per  = "China Beijing LongMai";
    printf("%s \n",per);

    printf("\n");
    p_ver = ver;

    while(*p_ver)   //到“/0”停止
    {
        printf("%c",*p_ver);
        p_ver++;
    }

    printf("\n");
    return 0;
}