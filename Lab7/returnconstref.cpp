#include <iostream>
#include <string>
using namespace std;

struct free_throws
{
    string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws & ft);
const free_throws & clone(free_throws & ft);

int main()
{
    free_throws one = {"Branch", 13, 14};
    free_throws two = {"Knott", 10, 16};
    free_throws three = {"Max", 7, 9};
    cout << "one: " << endl;
    display(one);

    free_throws dup1 = clone(one);
    display(dup1);
    cout << "After calling clone(), the one is: " << endl;
    display(one);

    free_throws dup2 = clone(two);

    cout << "The dup2 is " << endl;
    display(dup2);
    cout << "After calling clone(), the two is: " << endl;
    display(two);
    
    return 0;
}
void display(const free_throws & ft)
{
    cout << "Name: " << ft.name << '\n';
    cout << " Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}

const free_throws & clone(free_throws & ft)
{
    ft.percent = 5;

    return ft; //return a reference parameter
}