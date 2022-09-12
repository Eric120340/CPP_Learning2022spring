#include <iostream>

using namespace std;

template<class T>
T Max(T a, T b){
    if (a >= b) return a;
    else return b;
}

int main() {
    int a = 3, b = 5;
    double a2 = 3.5, b2 = 10.3;
    string c = "Hello", d = "World";

    cout << "the max of " << a << " and " << b << " is "
    << Max(a, b) << endl;

    cout << "the max of " << a2 << " and " << b2 << " is "
         << Max(a2, b2) << endl;

    cout << "the max of " << c << " and " << d << " is "
         << Max(c, d) << endl;

    return 0;
}
