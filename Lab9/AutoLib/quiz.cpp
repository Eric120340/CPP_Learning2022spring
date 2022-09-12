#include <iostream>
using namespace std;
/* namespace { void func(){cout << "a=10" <<endl;}}
int main(){   
func();   
return 0;
} */

namespace A{    int a = 100;   }
void funb(){int a = 200; cout << "a = " << A::a << endl;}
int main(){    funb();  return 0;}