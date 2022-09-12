#include <iostream>
using namespace std;

void trystat();

/*
You create such a variable by applying the static modifier to a variable defined inside a block. 
When you use it inside a block, static causes a local variable to have static storage duration. If 
you initialize a static local variable, the program initializes the variable once.
*/

int main()
{
    for (int i = 1; i <= 3; i++)
    {
        cout << " Here comes iteration " << i << ":\n";
        trystat();
    }

    return 0;
}

void trystat()
{
    int fade = 1;        // auto variable
    static int stay = 1; // Static variable

    cout << "fade = " << fade++ << " and stay = " << stay++ << endl;
}