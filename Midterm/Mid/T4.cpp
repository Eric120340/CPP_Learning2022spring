#include <iostream>

using namespace std;

struct PC
{
    int year;
    char brand[16];
    int value;
};

struct Student
{
    int studentID;
    char name[16];
    PC *computer;
};

int main()
{
    int n,com;
    Student stu[n];
    PC pc[n];
    
    for (int i = 0; i < n; i++)
    {
    cin.sync();
    cin >> pc[i].year;
    cin.get(pc[i].brand,16);
    cin >> pc[i].value;
    cin.get();
    }

    for (int i = 0; i < n; i++)
    {
    cin.sync();
    cin >> stu[i].studentID;
    cin.get(stu[i].name,16);
    cin >> com;
    stu[i].computer = com;
    cin.get();
    }

    for (int i = 0; i < n; i++)
    {
        
    }
    

    return 0;
}
