#include <iostream>
using namespace std;

void report_count();
void accumulate(int n);
int count = 0;  //file scope, external linkage

int main()
{
    int value;  //automatic variable 
    register int i; //register variable

    cout << "Enter a positive integer(0 to quit):";
    while(cin >> value)
    {
        if (value == 0)
        {
            break;
        }
        if (value > 0)
        {
            ++count;
            for ( i = value; i >= 0; i--)
            {
                accumulate(i);
            }
            cout << "Enter a positive integer(0 to quit):";
        }
    }
    report_count();

    return 0;
}

void report_count()
{
    cout << "Loop executed " << count << " times.\n";
}

