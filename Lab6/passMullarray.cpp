#include <iostream>
using namespace std;

void square(int (*p)[3], int n);

int main()
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

    square(a, 2);
    return 0;
}

void square(int (*p)[3], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp = *(*(p + i) + j);
            cout << temp * temp << " ";
        }
        cout << endl;
    }
}