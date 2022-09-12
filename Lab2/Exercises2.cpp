#include <iostream>
using namespace std;

int main()
{
    long long  seconds;
    long days,hours,minutes,sec;
    cout << "Enter the number of seconds: " << endl;
    cin >> seconds;
    days = seconds / (24*60*60);
    hours = (seconds % (24*60*60)) / (60*60);
    minutes = ((seconds % (24*60*60)) % (60*60)) / 60;
    sec = seconds % 60;
    cout << days << "days, " << hours << "hours, " << minutes << "minutes," << sec << "seconds" << endl;
    return 0;

}