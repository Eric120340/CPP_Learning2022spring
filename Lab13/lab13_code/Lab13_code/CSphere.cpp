//
// Created by lenovo on 2022/5/25.
//

#include "CSphere.h"
#include <cmath>

#define PI acos(-1)
using namespace std;

CSphere::CSphere() {
    this->radius = 1;
}

CSphere::CSphere(double r) {
    this->radius = r;
}

CSphere::CSphere(const CSphere &sphere) {
    this->radius = sphere.radius;
}

double CSphere::GetVolume() {
    return 4.0 / 3.0 * PI * pow(this->radius, 3);
}

double CSphere::GetArea() {
    return 4 * PI * pow(this->radius, 2);
}

void CSphere::Show() {
    cout << "Sphere radius: " << this->radius << endl;
    cout << "Sphere volume: " << this->GetVolume() << " Sphere area: " << this->GetArea() << endl;
}