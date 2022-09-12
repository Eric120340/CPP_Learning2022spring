#include <iostream>
using namespace std;
#define ArraySize 5

void sum(int *, int *, int);

int main()
{
    int arr1[ArraySize] = {10,20,30,40,50};
    int arr2[ArraySize] = {1,2,3,4,5};

    sum(arr1, arr2, ArraySize);
    cout << "Result" << endl;
    for (int i = 0; i < ArraySize; i++)
    {
        cout << arr1[i] << endl;
    }
    
    return 0;
}

void sum(int *pa, int *pb, int n)
{
    for (int i = 0; i < n; i++, pa++, pb++)
    {
        *pa += *pb;
    }
}