#include <iostream>
using namespace std;

void Displaymenu()
{
    cout << "====================================================================" << endl;
    cout << "                               MENU                                 " << endl;
    cout << "====================================================================" << endl;
    cout << "       1.Add" << endl;
    cout << "       2.Subtract" << endl;
    cout << "       3.Multiplay" << endl;
    cout << "       4.Divide" << endl;
    cout << "       5.Modulus" << endl;
}

int Add(int a, int b)
{
    return a + b;
}

int Substract(int a, int b)
{
    return a - b;
}

int Multiply(int a, int b)
{
    return a * b;
}

int Divide(int a, int b)
{
    return a / b;
}

int Modulus(int a, int b)
{
    return a % b;
}

int main()
{
    //Show menu
    Displaymenu();
    int YourChoice;
    int a, b;
    char confirm;
    do
    {
        cout << "Enter your choice(1~5):";
        cin >> YourChoice;
        cout << "Enter your integer numbers:";
        cin >> a >> b;
        cout << endl;
        switch (YourChoice)
        {
        case 1:
            /* code */
            cout << "Result: " << Add(a,b) << endl;
            break;

        case 2:
            /* code */
            cout << "Result: " << Substract(a,b) << endl;
            break;

        case 3:
            /* code */
            cout << "Result: " << Multiply(a,b) << endl;
            break;

        case 4:
            /* code */
            cout << "Result: " << Divide(a,b) << endl;
            break;
        
        case 5:
            /* code */
            cout << "Result: " << Modulus(a,b) << endl;
            break;
        }
        cout << "Press y or Y to continue:";
        cin >> confirm;
    } while (confirm == 'y' || confirm == 'Y');
    
    return 0;
}