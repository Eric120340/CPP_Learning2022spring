#include <iostream>
using namespace std;

class Base {
    int i;
    public:
        Base(int n) {i =n;} 
        ~Base(){}
        void show();
        int Geti() {return i;} };
class Derived:private Base {
    int j;
    Base aa;
    public:
        Derived(int n, int m, int p):Base(m), aa(p){j=n;}
        ~Derived(){}
        void show() {
            cout << j << "," << aa.Geti() << endl;
        }
};

int main() {
    Derived obj(8,13,24);
    obj.show();
    return 0;
}
