#include <iostream>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <cstring>
#include <string.h>
using namespace std;


int main()
{
    string input;
    ofstream myfile1;
    myfile1.open("file1.txt");
    if (myfile1.is_open())   //Check if open correctly
    {
        cout << "Please input a string: ";
        //Write in sentences
        getline(cin,input);
        myfile1 << input << endl;
        cout << input <<endl;
        myfile1.close(); //Close the file 
    }
    else
    {
        cout << "Fail to open the file1\n";
    }

    transform(input.begin(),input.end(),input.begin(),::toupper);
    
    ofstream myfile2;
    myfile2.open("file2.txt");
    if (myfile2.is_open())   //Check if open correctly
    {
        myfile2 << input << endl;
        cout << input <<endl;
        myfile2.close(); //Close the file 
    }
    else
    {
        cout << "Fail to open the file2\n";
    }

    return 0;
}