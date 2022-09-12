#include <iostream>
using namespace std;

double refcube(const double &ra);

int main()
{
    double side = 3.0;
    double *pd = &side;
    double &rd = side;
    /*都是相通的值*/
    cout << refcube(side) << "\t" << refcube(*pd) << "\t" << refcube(rd) << endl;

    return 0;
}
double refcube(const double &ra)
{
    return ra * ra * ra;
}