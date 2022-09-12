#include <iostream>
#include <string>
using namespace std;

void fill_array(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (double)rand() / ((double)rand() + 0.1);
    }
}

void show_array(double *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse_array(double *arr, int size)
{
    int temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main()
{
    int Size, Temp, Max, Min;
    cout << "Enter the size of an array:";
    cin >> Size;
    double arr[Size];
    fill_array(arr, Size);
    for (int i = 0; i < Size; i++)
    {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> Temp;
        arr[i] = Temp;
        if (i == 0)
        {
            Min = Temp;
        }
        if (i == Size - 1)
        {
            Max = Temp;
        }
    }
    show_array(arr, Size);

    reverse_array(arr, Size);
    show_array(arr, Size);

    reverse_array(arr, Size);
    arr[0] = Max;
    arr[Size - 1] = Min;
    show_array(arr, Size);
    return 0;
}