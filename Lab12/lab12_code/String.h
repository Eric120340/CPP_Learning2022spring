#include <iostream>
#ifndef STRING_H
#define STRING_H
using namespace std;
/**
 * @brief 
 * There is a pointer-to-char member in the class definition. It should use new operator in the 
 * constructor to allocate space for the string. The constructor must allocate enough memory to 
 * hold the string, and then it must copy the string to that location.
 * 
 */

class String
{
private:
    char* m;
public:
    String(const char* cstr = 0);
    ~String();
    friend ostream& operator << (ostream &os, const String &c);
};

String::String(const char* cstr)
{
    if (cstr)
    {
        m = new char[strlen(cstr) + 1];
        strcpy(m,cstr);
    }
    else
    {
        m = new char[1];
        *m = '\0';
    }
    
}

String::~String()
{
    delete[] m;
}

#endif