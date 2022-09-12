#include "pair.h"
#include <iostream>

#define EVEN_PAIR 3
#define ODD_PAIR 4

Pair *splitPair(string s, int &length)
{
    // TODO finish this function, do not modify the parameters

    int count = 0;
    int string_length = s.length();
    
    Pair *pair = new Pair[string_length/2];

    if (s.length() == EVEN_PAIR)
    {
        pair[count].a = s[0];
        pair[count].b = s[2];
        length++;
    }

    while (s.length() >= ODD_PAIR)
    {   
        string string_4 = s.substr(0, 4);
        pair[count].a = string_4[0];
        pair[count].b = string_4[2];

        count++;
        length++;

        pair[count].a = string_4[1];
        pair[count].b = string_4[3];

        count++;
        length++;
        s = s.substr(4);
    }
    
    return pair;
}

void printPair(Pair *pair)
{
    // TODO finish this function, do not modify the parameters
    cout << pair->a << " " << pair->b << "\n";
}
