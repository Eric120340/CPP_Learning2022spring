#include <iostream>

#include "driver.h"
#include "OutOfRangeException.h"

using namespace std;

double calculateAverage(int a, int b, int c, int d){
    if (a < 0 || a > 100)
        throw OutOfRangeException(1, a);
    if (b < 0 || b > 100)
        throw OutOfRangeException(2, b);
    if (c < 0 || c > 100)
        throw OutOfRangeException(3, c);
    if (d < 0 || d > 100)
        throw OutOfRangeException(4, d);
    return (a + b + c + d) / 4.0;
}

int main() {
   Car car;
   Driver driver;

   car.showInfo();
   car.velup(120);
   driver.setmode(car);
   car.showInfo();
   driver.veldown(car, 100);
   driver.velup(car, 150);

    // char ans;
    // do{
    //     int a, b, c, d;
    //     cout << "Please enter 4 marks: ";
    //     cin >> a >> b >> c >> d;
    //     try{
    //         double result = calculateAverage(a, b, c, d);
    //         cout << "the average is " << result << endl;
    //     }catch (OutOfRangeException& e){
    //         e.what();
    //     }
    //     cout << "would you like to calculate again? (y/n)";
    //     cin >> ans;
    // }while(ans == 'y');

    // cout << "bye bye!";

    return 0;
}
