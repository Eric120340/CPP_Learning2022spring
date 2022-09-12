#include <stdio.h>
int main(void)
{
    char *name[] = {"China", "Beijing", "Chenyifei"};
    char **p_name;
    int i;
    
    printf("name[0] : %p\n",name[0]);
    printf("name[1] : %p\n",name[1]);
    printf("name[2] : %p\n",name[2]);
    printf("\n");

    p_name = &name[0];
    printf("&name[0] : %p\t%p\n",p_name,*p_name);

    p_name = &name[1];
    printf("&name[1] : %p\t%p\n",p_name,*p_name);

    p_name = &name[2];
    printf("&name[2] : %p\t%p\n",p_name,*p_name);

    printf("\n");
    p_name = name;
    for(i=0;i<3;i++)
    {
        printf(" %s ",*(p_name+i));         //对指向指针的指针变量进行初始化，让p_name指向指针数组name的第一个元素
    }                                       //name是数组名，指针数组首元素的地址。
    printf("\n");
    return 0;
}