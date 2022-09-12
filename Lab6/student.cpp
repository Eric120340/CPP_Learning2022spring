#include <iostream>
#include "student1.h"
using namespace std;

void recordstudent(student *st)
{
    cout << "Input information: " << endl;
    cin >> st->id;
    cin >> st->name;
    cin >> st->score;
}

void printstudent(student *st)
{
    cout << "ID: " << st->id << endl;
    cout << "Name: " << st->name << endl;
    cout << "score: " << st->score << endl;
}