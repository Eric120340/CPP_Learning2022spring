#include <iostream>
#include <fstream>
using namespace std;
/*ofstream可以自己创建好文本然后进行操作*/
int main()
{
    ofstream myfile; // create an object of ofstream
    myfile.open("Example.txt");//Using open() method to associate the object with a file

    if (myfile.is_open())   //Check if open correctly
    {
        cout << "Open the file for writing a string: \n";
        //Write in sentences
        myfile << "This is an example of writing a string to a file.\n";
        myfile << "Hello Dbq!\n";

        myfile.close(); //Close the file 
    }
    else
    {
        cout << "Fail to open the file\n";
    }
    return 0;
}