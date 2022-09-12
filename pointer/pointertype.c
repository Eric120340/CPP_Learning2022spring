#include<stdio.h>

int main(void)
{
    char str[] = "Beijing is the captial of China!";
    printf("size of str: %d\n",sizeof(str));

    char *pstr;
    pstr  = &str;    //pstr point to str
    printf("str: %s\n",str);
    int j;
    for(j=0;j<33;j++)
    {
        printf("%c",*pstr);
        pstr++;
    }
printf("\n");


    int i,num[3];
    int *pnum;
    pnum = num;
for(i=0;i<3;i++)
{
    *pnum = i;
    pnum++;
}
for(i=0;i<3;i++)
{
    printf("%d\n",num[i]);

}

    //char str[] = {"C is an amazing language"};
    printf("%s\n",str);
    

    //int *pStu;          //定义指针变量pStu，并且指向int类型变量
    //static int *pStu;   //定义指向静态变量
    int x, *p;
    int array[4] = {11,12,13,14};
    int *p_New, *p_old;
    p_New = array;
    p_New++;
    p_old = p_New + 2;
    printf("The p_New = %d\nThe p_old = %d\n",*p_New,*p_old);
    printf("The number of elements between p_New and p_old = %ld\n",p_old-p_New);


    p = &x;
    x = 10;
    printf("%d\n",*p);
    return 0;

}