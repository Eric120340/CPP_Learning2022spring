#include <stdio.h>

void reverse(int *element, int num)
{
    int t;
    for (int i = 0; i < num/2; i++)
    {
        t=*(element+i);
        *(element+i)=*(element+num-i-1);
        *(element+num-i-1)=t;
    }
}
int main()
{
    int *tmp;
    int array[5];
    printf("Enter 5 integers:\n");
    
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",array+i);
    }
    
    reverse(array,5);
    printf("The elements of the array in reverse order are:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",*(array+i));
    }
    
    return 0;
    
}