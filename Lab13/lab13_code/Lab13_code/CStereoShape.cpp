//
// Created by lenovo on 2022/5/23.
//

#include <iostream>
#include "CStereoShape.h"
using namespace std;

double CStereoShape::GetArea() {
    cout << "CStereoShape::GetArea()" << endl;
    return 0.0;
}
double CStereoShape::GetVolume() {
    cout << "CStereoShape::GetVolume()" << endl;
    return 0.0;
}

void CStereoShape::Show() {
    cout << "CStereoShape::Show()" << endl;
}

CStereoShape::CStereoShape() {
    numberOfObject++;
}

int CStereoShape::numberOfObject = 0;

