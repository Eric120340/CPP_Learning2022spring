#include "pascal.h"

int pascal(int row, int column)
{
    if (row < column) // when row is smaller than column
    {
        return 0;
    }
    else
    {
        if (column == 0 || row == 0) // when row and column at 0 place
            return 1;
        else if (column == row) // when row and column are equal
            return 1;
        else
            return pascal(row - 1, column) + pascal(row - 1, column - 1);
    }
}
