#include <iostream>
#include <cmath>
using namespace std;

int find(int num)
{
    for (int i = 2; i < num - 1; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int m, n;
    int count = 0;
    cin >> m >> n;
    for (int i = m; i <= n; i++)
    {
        int k = find(i);
        if (k == 1)
        {
            cout << i << " ";
            count += 1;
            if (count % 10 == 0)
            {
                cout << endl;
            }
        }
    }
}
