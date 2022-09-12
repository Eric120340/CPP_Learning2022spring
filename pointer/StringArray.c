#include <stdio.h>
#define VER 22

int main(void)
{
    char *str[ ] = {"China", "Beijing","Haidian"};
    printf("str[0]: %s \nstr[1]: %s \nstr[2]: %s\n",str[0],str[1],str[2]);
    
    char ver[VER] = "Gate Ver1.00 2022.4.3";
    char *p_ver;
    int idx;
    for(idx = 0; idx < VER ; idx++)
    {
        printf("%c",ver[idx]);
    }

    p_ver = ver;
    while(*p_ver)       //loop is over when *p_ver = '\o'
    {
        printf("%c\t",*p_ver);
        printf("%p",p_ver); //Output the address
        printf("\n");

        p_ver++;        //pointer++
    }
    printf("\n");
    return 0;
/*     int temp;
    int week[WEEKNUM] = {1,2,3,4,5,6,7};
    printf("Please input today: ");
    scanf("%d",&temp);
    if(temp <= WEEKNUM)
    {
        printf("Tomorrow is %d\n",temp);
    }else{
        printf("Wrong Input, error!!!\n");
    }
    return 0;
 */
}