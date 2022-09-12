#include <iostream>
#include "student1.h"
using namespace std;


void printstudent(student *st);
void recordstudent(student *st);
int main()
{
    student record;
/*
    record.id = 1;
    stpcpy(record.name, "Raju");
    record.score = 86.5;*/
    recordstudent(&record);
    printstudent(&record);
}
