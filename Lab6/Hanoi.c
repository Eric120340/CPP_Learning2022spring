#include <stdio.h>
void printdisk(char x, char y)
{
    printf("%c----->%c\n",x,y);
}

void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printdisk(a,c);
    }
    else
    {
        hanoi(n-1,a,c,b);
        printdisk(a,c);
        hanoi(n-1,b,a,c);
    }
}

void main()
{
    int n;
    printf("Input n: ");
    scanf("%d",&n);
    hanoi(n,'A','B','C');
}