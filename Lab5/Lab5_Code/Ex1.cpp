#include <iostream>
#define BREAKSIGNAL 0
using namespace std;

int main()
{
    int number = 0, sum = 0;
    do
    {
        cout << "Enter an integer number: ";
        cin >> number;
        sum += number;
        cout << "The cumulative sum of the entries to date is: " << sum << endl;
    } while (number != BREAKSIGNAL);
    
    return 0;
}