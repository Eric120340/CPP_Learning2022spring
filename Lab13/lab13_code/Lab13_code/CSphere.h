//
// Created by lenovo on 2022/5/25.
//

#ifndef LAB13_CSPHERE_H
#define LAB13_CSPHERE_H


#include "CStereoShape.h"

class CSphere : public CStereoShape
{
private:
    double radius;

public:
    CSphere();
    CSphere(double r);
    CSphere(const CSphere &sphere);
    double GetVolume() override;

    double GetArea() override;

    void Show() override;
};


#endif //LAB13_CSPHERE_H
