#include <stdio.h>

int main()
{
    char str[20];
    printf("Enter a string\n");
    fgets(str,20,stdin);       //更安全
    printf("String: ");
    puts(str);

    return 0;
}