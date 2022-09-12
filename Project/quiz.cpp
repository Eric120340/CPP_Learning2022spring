#include <iostream>

class Date
{
private:
    int month = 5;
    int day = 6;

public:
    Date operator++(int);
    void display();
};
Date Date::operator++(int)
{
    day++;
    return *this;
}
void Date::display() { std::cout << std::endl; }
int main()
{
    Date d1;
    d1++;
    d1.display();
}