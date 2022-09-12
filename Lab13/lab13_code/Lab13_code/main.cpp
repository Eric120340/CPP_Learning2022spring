//
// Created by lenovo on 2022/5/25.
//

#include <iostream>
#include "CStereoShape.h"
#include "CCube.h"
#include "CSphere.h"
using namespace std;
int main() {
    
    CCube a_cube(4.0,5.0,6.0);
    CSphere c_sphere(7.9);
    CStereoShape *p = &a_cube;
    p->Show();
    p = &c_sphere;
    p->Show();
    cout << CStereoShape::GetNumOfObject() << " objects are created. "<<endl;
    delete p;
    return 0;
}