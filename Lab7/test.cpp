#include <stdio.h>
#include <iostream>
int main()
{
/*     int a = 1, b = 3, c = 5; 
int *p1 = &a, *p2 = &b, *p = &c; 
*p = *p1 * (*p2); 
printf("%d\n", c);  */

/* int **k, *a, b = 100;
a = &b; 
k = &a; 
printf("%d\n", **k); */

/* char a[] = "programming", b[] = "language"; 
char *p1, *p2; int i; p1 = a; p2 = b; 
for(i = 0; i < 7; i++){ 
     if(*(p1+i) == *(p2+i)) 
          printf("%c", *(p1+i)); 
}  */

int i, j, k;
for(i = 0, j = 10; i<=j; i++, j--){       
      k = i+j; 
}
std::cout << k << std::endl; 
    return 0;

}