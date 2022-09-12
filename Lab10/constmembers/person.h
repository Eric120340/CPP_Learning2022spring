#include <iostream>

#ifndef PERSON_H
#define PERSON_H
class Person
{
private:
    const int SIZE = 10;
    int age = 20;

public:
    Person(){ };    //空的默认构造器
    Person(int a){ age = a;};

    void Show()
    {
        std::cout << "The size is:" << SIZE << ", the age is:" << age << std::endl;
    }
};

#endif