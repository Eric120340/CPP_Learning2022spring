//
// Created by gfzum on 2022/6/9.
//

#ifndef LAB15_OUTOFRANGEEXCEPTION_H
#define LAB15_OUTOFRANGEEXCEPTION_H

#include "exception"
#include <iostream>

class OutOfRangeException : std::exception{
public:
    int index;
    int value;

    OutOfRangeException(int i, int v) : index(i), value(v){};

    const char * what() const noexcept override{
       std:: cout << "the parameter " << index << " is " << value
       << " which out of range 0 - 100" << endl;
    }
};

#endif //LAB15_OUTOFRANGEEXCEPTION_H
