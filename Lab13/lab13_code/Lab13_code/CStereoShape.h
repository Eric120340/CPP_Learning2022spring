//
// Created by lenovo on 2022/5/24.
//

#ifndef LAB13_CSTEREOSHAPE_H
#define LAB13_CSTEREOSHAPE_H
#include <iostream>
class CStereoShape {
private:
    static int numberOfObject;

public:
    CStereoShape();
    virtual double GetArea();
    virtual double GetVolume();
    virtual void Show();
    static int GetNumOfObject(){
        return numberOfObject;
    }

};

#endif //LAB13_CSTEREOSHAPE_H