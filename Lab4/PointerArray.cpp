#include <iostream>
using namespace std;

int main()
{
    float arr[5];
    float *ptr;
    cout << "Display address using array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "&array[" << i << "]= " << &arr[i] << endl; 
    }

    ptr = arr;
    cout << "Display address using pointer: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "ptr + " << i << " = " << ptr + i << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i * 2;
    }

    cout << "Display the value of elements using pointer: " <<  endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "*(ptr +" << i << ") = " << *(ptr + i) << endl;
    }
    
    cout << "\nThe size of array is: " <<  sizeof(arr) << endl;
    cout << "The size of ptr is :" << sizeof(ptr) << endl;

    return 0;
    
}
