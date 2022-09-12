#include <iostream>
using namespace std;

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    /*新建一个结构体，把结构体的地址给ps*/
    inflatable *ps = new inflatable;    //allocate memory for structure
    cout << "Enter name of inflatable item: ";
    cin.get(ps->name, 20);//->is  a way to access the number (value)
    cout << "Enter volume of cubic feet: ";
    cin >> (*ps).volume;//using * to access the member
    cout << "Enter price: $";
    cin >> ps -> price;
    //访问ps中的元素
    cout << "Name: " << (*ps).name << endl;
    cout << "Volume: " << ps->volume << endl;
    cout << "Price: " << ps->price << endl;

    delete ps;

    return 0;
}
