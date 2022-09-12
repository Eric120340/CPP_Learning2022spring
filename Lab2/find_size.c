#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Find size of the fundamental data type: \n");
    printf("-----------------------------------------\n");
    printf("Size of char:       %ld\n",sizeof(char));
    printf("Size of short:      %ld\n",sizeof(short));
    printf("Size of int:        %ld\n",sizeof(int));
    printf("Size of long:       %ld\n",sizeof(long));
    printf("Size of long long:  %ld\n",sizeof(long long));
    printf("Size of float:      %ld\n",sizeof(float));
    printf("Size of double:     %ld\n",sizeof(double));
    printf("Size of long double:%ld\n",sizeof(long double));
    printf("Size of bool:       %ld\n",sizeof(bool));

    
    printf("Input a char:\n");
    char b;
    scanf("%c",&b);
    printf("THe char is: %c",b);
    return 0;
}