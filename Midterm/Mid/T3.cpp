#include <iostream>

using namespace std;

#define MOD 100000007

inline unsigned int Fib(unsigned int n)
{
    n = n % MOD;
    if (n == 1 || n == 2)
        return 1;
    else
        return ((Fib(n-1) % MOD) + (Fib(n-2) % MOD)) % MOD;
}

int main()
{
    unsigned int n;
    cin >> n;
    //现在我们要计算fb(n)除以3的余数
    cout << Fib(n) % 3;
    return 0;
}


