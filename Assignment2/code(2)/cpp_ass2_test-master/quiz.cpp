#include <iostream>
using namespace std;

/* void sum(int num=10){
    int i, s = 0;
    for(i = 1; i <= num; i++){  s = s + i; }
    cout << s << endl;}
int main(){
    sum(100);
    sum();
    return 0;
} */

/* int main()
{
    int a[4] = {2, 4, 6};
    int y = 0, *p = a;
    for (; *p++;)
    {
        if (*p)
        {
            y += *p;
        }
    }
    cout << y << endl;
} */

/* void Max(int a) { cout << "Max 1" << endl; }
void Max(int a, int b) { cout << "Max 2" << endl; }
void Max(int a, int b, int c) { cout << "Max 3" << endl; }
int main(){ Max(1,2,3);  return 0;} */

int main(){   
    int a;    int &b = a;    b = 10;   
    cout << a << endl;
    return 0;
}