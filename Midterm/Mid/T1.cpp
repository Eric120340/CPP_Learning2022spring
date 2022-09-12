#include <iostream>
#include <cstring>

using namespace std;

void Small_number(int a, int b);

int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    //每一个处于a,b区间的数 ，在1-9中的返回英文单词
    Small_number(a,b);
    return 0;
}

void Small_number(int a, int b)
{
    string result;
    int temp = a;
    for (int i = a; i <= b; i++)
    {
        //小数
        if (temp <= 9)
        {
            switch (temp)
            {
            case 1:
                result = "one";
                break;
            case 2:
                result = "two";
                break;
            case 3:
                result = "three";
                break;
            case 4:
                result = "four";
                break;
            case 5:
                result = "five";
                break;
            case 6:
                result = "six";
                break;
            case 7:
                result = "seven";
                break;
            case 8:
                result = "eight";
                break;
            case 9:
                result = "nine";
                break;

            default:
                break;
            }
        }

        //超过9判断奇偶性
        if (temp > 9)
        {
            if (temp % 2 == 0)
            {
                result = "even";
            }
            else
            {
                result = "odd";
            }
            
        }
        cout << result << endl;
        temp++;
    }
}