#include "pair.h"
#include <iostream>

#define EVEN_PAIR 3
#define ODD_PAIR 4
#define unit_32 int

void printPair(Pair *pair)
{
    // TODO finish this function, do not modify the parameters
    cout << pair->a << " " << pair->b << "\n";
}

Pair *splitPair(string s, int &length)
{
    // TODO finish this function, do not modify the parameters

    unit_32 site = 0;
    unit_32 string_length = s.length();

    Pair *pair = new Pair[string_length / 2];

    if (EVEN_PAIR == s.length())
    {
        length++;
        pair[site].b = s[2];
        pair[site].a = s[0];
    }
    else

        while (ODD_PAIR <= s.length())
        {
            string string_4 = s.substr(0, 4);
            pair[site].b = string_4[2];
            pair[site].a = string_4[0];

            length++;
            site++;

            pair[site].b = string_4[3];
            pair[site].a = string_4[1];

            length++;
            site++;

            s = s.substr(4);
        }

    return pair;
}
