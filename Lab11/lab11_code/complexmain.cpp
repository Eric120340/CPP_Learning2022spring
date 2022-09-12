#include "complex.h"

int main()
{
    complex c1(3.0,4.0);
    complex c2(2.0,6.0);

    cout << "c1 is ";
    c1.show();
    cout << endl;

    cout << "c2 is ";
    c2.show();
    cout << endl;

    cout << "~c1 is ";
    complex c_conj = ~c1;
    c_conj.show();
    cout << endl;

    complex c = c1 + c2;    //c1调用+，传入的参数是c2
    complex c_r = c1 + 2;
    cout << "c1 + c2 is ";
    c.show();
    cout << endl;
    cout << "c1 + 2 is ";
    c_r.show();
    cout << endl;

    cout << "c1 - c2 is ";
    complex c_d = c1-c2;
    c_d.show();
    cout << endl;

    cout << "c1 - 2 is ";
    complex c_dd = c1-2;
    c_dd.show();
    cout << endl;

    cout << "c1 * c2 is ";
    complex c_product = c1*c2;
    c_product.show();
    cout << endl;

    cout << "2 * c1 is ";
    complex c_product_double = c1*2;
    c_product_double.show();
    cout << endl;

    complex c3 = c2;
    cout << "c2 == c3 is ";
    c2==c3;
    cout << endl; 
    cout << "c2 != c3 is ";
    (c2!=c3);
    cout << endl;
    cout << "c1 != c3 is ";
    (c1!=c3);
    cout << endl;
    cout << "Done." << endl;


    complex d;

    cout << "Enter a complex number: ";

    cout << "real: ";
    
    cout << "imaginary: ";
    
    //cin >> d;
    //cout << "d" << " is " << d;
    return 0;
}