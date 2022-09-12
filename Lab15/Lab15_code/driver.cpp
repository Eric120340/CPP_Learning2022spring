

#include "driver.h"

bool Car::velup(int v) {
    if (v < 0) return false;

    velocity += v;
    cout << "increase velocity by car, its mode is " << (mode==0?"Off":"On") <<
         ", velocity is " << velocity;

    if (velocity > Maxvel) cout << ". It is out of Maxvel";

    cout << endl;

    return true;
}

bool Car::veldown(int v) {
    if (v > 0) return false;
    velocity -= v;
    cout << "decrease velocity by car, its mode is " << (mode==0?"Off":"On")<<
         ", velocity is " << velocity;
    if (velocity < Minvel) cout << ". It is lower than Minvel";
    cout << endl;
    return true;
}

bool Car::ison() const {
    return mode == On;
}

int Car::getvel() const {
    return velocity;
}

void Car::showInfo() const {
    cout << "info: mode is " << (mode==0?"Off":"On") << ", velocity is " << velocity << endl;
}
bool Driver::velup(Car &car, int v) {
    if (v < 0) return false;

    car.velocity += v;
    cout << "increase velocity by driver, its mode is " << (car.mode==0?"Off":"On")<<
         ", velocity is " << car.velocity;

    if (car.velocity > car.Maxvel) cout << ". It is out of Maxvel";

    cout << endl;

    return true;
}

bool Driver::veldown(Car &car, int v) {
    if (v < 0) return false;

    car.velocity -= v;
    cout << "decrease velocity by driver, its mode is " << (car.mode==0?"Off":"On") <<
         ", velocity is " << car.velocity;

    if (car.velocity < car.Minvel) cout << ". It is lower than Minvel";

    cout << endl;

    return true;
}

void Driver::setmode(Car &car) {
    cout << "Set the mode of car by driver: \nThe original mode of car is: " << (car.mode==0?"Off":"On") << endl;
    if (car.mode == car.On) car.mode = car.Off;
    else car.mode = car.On;
}

bool Driver::ison(Car &car) const {
    return car.mode == car.On;
}
