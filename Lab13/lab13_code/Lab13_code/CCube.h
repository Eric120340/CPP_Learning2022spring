//
// Created by lenovo on 2022/5/25.
//

#ifndef LAB13_CCUBE_H
#define LAB13_CCUBE_H
#include "CStereoShape.h"


class CCube : public CStereoShape {
private:
    double length;
    double width;
    double height;
public:
    CCube();
    CCube(double length, double width, double height);
    CCube(const CCube &cube);

    double GetVolume() override;

    double GetArea() override;

    void Show() override;
};


#endif //LAB13_CCUBE_H
