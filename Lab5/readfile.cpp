#include <iostream>
#include <fstream>
using namespace std;
/*infile 使用不能自己创建一个文本文件，需要提前创建好*/
int main()
{
    string contents;
    ifstream infile;
    infile.open("Example.txt");

    if (infile.is_open())
    {
        while (!infile.eof())   //检查是否到达文件的底部
        {
            getline(infile, contents); //读取文件的每一行
            cout << contents << endl;   //打印
        }
        infile.close();
    }
    else
    {
        cout << "Fail to open the file.\n";
    }

    return 0;
}