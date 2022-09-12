//
// Created by lenovo on 2022/5/25.
//

#include "CCube.h"
using namespace std;
CCube::CCube() {
    length = 1;
    width = 1;
    height = 1;
}

CCube::CCube(double length, double width, double height) {
    this->length = length;
    this->width = width;
    this->height = height;
}

CCube::CCube(const CCube &cube) {
    this->length = cube.length;
    this->width = cube.width;
    this->height = cube.height;
}

double CCube::GetVolume() {
    return length * width * height;
}

double CCube::GetArea() {
    return 2 * (length * width + length * height + width * height);
}

void CCube::Show(){
    cout << "Cube length: " <<length <<" width: " <<width <<" height: " <<height <<endl;
    cout << "Cube volume: " <<GetVolume() <<" Cube area: " <<GetArea() <<endl;
}

