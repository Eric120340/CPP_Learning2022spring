#include <iostream>
#include <iomanip>
#define SIZE 2

const int arrsize = 3;
using namespace std;

int main()
{
    int a[SIZE] = {0};
    double b[arrsize] = {1};

    cout << "The elements in a are:" << a[0] << "," << a[1] << endl;
    cout << "The elements in b are:" << b[0] << "," << b[0] << endl;

    return 0;
}