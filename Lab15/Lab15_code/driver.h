
#ifndef LAB15_DRIVER_H
#define LAB15_DRIVER_H
#include "iostream"

using namespace std;

class Driver;

class Car{
private:
    enum {Off, On};
    enum {Minvel, Maxvel = 200};
    int mode;
    int velocity;
public:
    friend class Driver;
    Car (int m = On, int v = 50):mode(m), velocity(v){}
    bool velup(int v);
    bool veldown(int v);
    bool ison() const;
    int getvel() const;
    void showInfo() const;
};

class Driver {
public:
    bool velup(Car & car, int v);
    bool veldown(Car & car, int v);
    void setmode(Car & car);
    bool ison(Car &car) const;
};



#endif //LAB15_DRIVER_H
