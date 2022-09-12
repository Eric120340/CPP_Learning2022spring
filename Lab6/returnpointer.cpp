#include <iostream>
using namespace std;

char * match(char *s, char ch)
{
    while(*s != '\0')
    {
        if(*s == ch)
        {
            return s;   //返回指针参数
        } 
        else
            s++;
    }
    return (NULL);
}

int main()
{
    char ch, str[81], *p = NULL;

    cout << "Please input a string:\n";
    cin.getline(str,81);
    cout << "Please input a character\n";
    ch = getchar();

    if((p = match(str,ch)) != NULL)
    {
        cout << ch << " is in the string." << endl;
        cout << "The rest of string is: " << p << endl;
    }
    else
    {
        cout << ch << " is not in the string " << endl;
    }
        
        
    return 0;
}