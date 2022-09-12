#include "rational.h"

int main()
{
    rational a = 10;
    rational b(1,2);

    rational c = a * b;

    c.show();

    return 0;
}