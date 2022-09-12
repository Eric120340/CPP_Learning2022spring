#include "rational.h"

const rational operator * (const rational& lhs, const rational& rhs)
{
    return rational(lhs.getN() * lhs.getD() * rhs.getD()); 
}
