#include <iostream>
using namespace std;

long factorial(int n);

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        cout << i << "!= " << factorial(i) << endl;
    }
    
    return 0;
}

long factorial(int n)
{
    static long product = 1;

    product *= n;

    return product;
}