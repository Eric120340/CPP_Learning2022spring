//等差公式 xor[i] = arraystart + 2 * i.
//请打印已创建的数组和数组中所有元素的二进制文件
#include <iostream>

#include <string>
using namespace std;

void convert(int n);

int main()
{
    int len, arraystart;
    cin >> len;        // 数组长度
    cin >> arraystart; //数组的第一元素

    int array[len];
    array[0] = arraystart;
    //十进制
    for (int i = 0; i < len; i++)
    {
        array[i] = arraystart + 2 * i;
        cout << array[i];
        if (i <= len - 2)
        {
            cout << ",";
        }
    }
    cout << endl;

    //二进制 XOR
    long long xor_result = 0;

    for (int i = 0; i < len; i++)
    {
        xor_result ^= array[i];
    }
    convert(xor_result);

    return 0;
}

void convert(int n)
{
    int dec, rem, i = 1, sum = 0;
    dec = n;
    char repr[33] = {0};
    int size = 0;
    for (int tmp = dec; tmp; tmp >>= 1)
        size++;

    for (int i = 0; i < size; ++i)
        repr[i] = ((dec >> (size - i - 1)) & 1) ? '1' : '0';

    for (int i = 0; i < 32-size; i++)
    {
        cout << "0";
    }
    
    cout << repr << endl;

    /* int i, j = 0;
    int a[1000];
    i = n;
    while (i)
    {
        a[j] = i % 2;
        i /= 2;
        j++;
    }
    for (i = j - 1; i >= 0; i--)
        cout << a[i];*/
}
