#include <iostream>
#include "candybar.h"
using namespace std;

int main()
{
    CandyBar candybar_ref;
    CandyBar candybar_pointer;
    setCandyBar(candybar_pointer);
    showCandyBar(candybar_pointer);    
    setCandyBar(&candybar_ref);
    showCandyBar(&candybar_ref);
    
    return 0;
}