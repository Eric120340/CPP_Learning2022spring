#include <iostream>
using namespace std;

template <typename T>
T Max(T x, T y)
{
    return (x > y ? x : y);
}

int main()
{
    cout << "Max int = " << Max<int>(3,7) << endl;
    cout << "Max char = " << Max<char>('g','e') << endl;
    cout << "Max double = " << Max<double>(3.1, 7.9) << endl;

    return 0;
}
