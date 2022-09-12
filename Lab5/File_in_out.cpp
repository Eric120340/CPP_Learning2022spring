#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char input_name[80];
    int age;
    string readline;

    fstream finout("testfile.txt", ios::out | ios::in);

    if (finout.good())
    {
        cout << "Writing to a text file: " << endl;
        cout << "Please enter your name:";
        cin.getline(input_name, 80);
        cout << "Please enter your age:";
        cin >> age;
        finout << input_name << endl;
        finout << age << endl;

        finout.clear(); // reset the stream state
        finout.seekg(0);

        cout << "Reading from the txt file:" << endl;
        while (!finout.eof())
        {
            getline(finout, readline);
            cout << readline << endl;
        }
        finout.close();
    }
    else
    {
        cout << "testfile.txt could not be opened.\n";

        return 0;
    }
}