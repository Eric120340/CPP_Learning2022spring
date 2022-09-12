#ifndef CITIES_H
#define CITIES_H

#define NUM_CHINA 6
#include <iostream>
#include <istream> 
#include <streambuf>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool judge_city_in_China(string Sentence)
{
    string search[NUM_CHINA];
    string China = "China";
    istringstream read(Sentence);

    for (int i = 0; i < NUM_CHINA; i++)
    {
        getline(read, search[i], ',');
        if (search[i] == China)
            return 1;
    }
    return 0;
}
#endif