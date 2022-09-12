#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //Define and initialize array
    int test[3][2] = 
    {
        {2, -5},
        {4, 0},
        {9, 1}
    };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << test[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The size of test is: " << sizeof(test) << endl;

    return 0;
}