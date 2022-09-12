#include <stdio.h>

int main(void)
{
    char a;
    int b;
    float c;

    printf("Please Enter a Character: \n");
    scanf("%c",&a);
    printf("Please Enter a Integer Value: \n");
    scanf("%d",&b);
    printf("Please Enter a float Value: \n");
    scanf("%f",&c);
    printf("The value you input are:\nCharacter: %c, Integer: %d, Float: %0.3f\n",a,b,c);
    return 0;

}