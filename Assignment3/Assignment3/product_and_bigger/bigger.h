#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
// TODO finish inline template function bigger

template<typename T>
inline T bigger(T a, T b)
{
    T res;
    if (a == b)
        return a;
    
    res = (a > b) ? a : b;
    
    return res;
}

template<>
inline char * bigger<char *>(char *a, char *b)
{
    int ptr = strcmp(a,b);
    if(ptr > 0)
        return a;
    else if(ptr < 0)
        return b;
    else
        return a;
}

template<>
inline string bigger<string>(string a, string b)
{
    string result;
    int factor = a.compare(b);
    if (factor > 0)
    {
        return b;
    }
    else if(factor < 0)
    {
        return a;
    }
    return a;
}


