#include <iostream>
#include <stdio.h>
#include "Exercise2.h"
using namespace std;
using namespace SALES;
int main(){
    Sales s1, s2;
    double ar1[4] = {345.2,621.8,1073.5,0};
    setSales(s1, ar1, 4);
    showSales(s1);
    setSales(s2);
    showSales(s2);
    return 0;
}