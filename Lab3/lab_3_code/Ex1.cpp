#include <iostream>

using namespace std;

struct Person
{
    char FirstName[21];
    char LastName[21];
    char grade[4];
    int age;
    
};

int main()
{
    Person p1;
    cout << "What is your first name?";
    cin.get(p1.FirstName,21);
    cout << "What is your last name?";
    cin >> p1.LastName;
    cout << "What letter grade do you deserve?";
    cin >>p1.grade;
    cout << "what is your age?";
    cin >> p1.age;

    cout << "Information about Person:" << endl;
    cout << "Name: " << p1.FirstName << " " << p1.LastName << endl;
    cout << "Grade: " << p1.grade << endl;
    cout << "Age: " << p1.age << endl;

    return 0;
}