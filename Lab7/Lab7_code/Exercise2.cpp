#include <iostream>
#include <string>

using namespace std;

template <typename T>
T max5(T a[],int len)
{
    T max = a[0];
    for(int i = 1; i < len; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}

int main()
{
    int a[] = {1,2,3,4,5};
    double b[] = {1.1,2.2,3.3,4.4,5.5};
    cout << max5(a, 5) << endl;
    cout << max5(b, 5) << endl;
    return 0;
}