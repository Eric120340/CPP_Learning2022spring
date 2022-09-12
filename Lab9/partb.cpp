#include <iostream>
using namespace std;

extern int count;   //外部链接 external

static int total = 0;   //static，内部链接

void accumulater(int n)
{
    static int subtotal = 0;

    if(n <= 0)
    {
        cout << "loop cycle: " << count << endl;
        cout << "subtotal: " << subtotal << ", total: " << total << endl;
        subtotal = 0;
    }
    else
    {
        subtotal += n;
        total += n;
    }
}