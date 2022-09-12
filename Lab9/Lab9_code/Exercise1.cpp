#include <iostream>
#include <stdio.h>
using namespace std;

void swap_int(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int x = 10, y = 20;
    swap_int(x, y);
    cout << x << " " << y << endl;
    swap(&x, &y);
    cout << x << " " << y << endl;
    int *p = &x, *q = &y;
    swap(p, q);
    cout << x << " " << y << endl;

    return 0;
}