#include <iostream>
using namespace std;
#define BREAKSIGNAL 0

int main()
{
    float number, sum = 0.0;
    /*add number until user enters 0*/
    do
    {
        cout << "Enter a number(Enter 0 to teminate): ";
        cin >> number;
        sum += number;
    } while (number != BREAKSIGNAL);

    cout << "Sum = " << sum << endl;

    return 0;
}