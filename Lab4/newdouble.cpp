#include <iostream>
using namespace std;

int main()
{
    double *pvalue = NULL;  //Pointer initial with NULL
    pvalue = new double;    //Request memory for the variable

    *pvalue = 1294948.98;   //Store value at all allocated address
    cout << "Value of pvalue: " << *pvalue << endl;
    
    delete pvalue;  //Free up the memory
    return 0;
}