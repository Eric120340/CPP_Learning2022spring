

#include "iostream"
#include "Matrix.h"

using namespace std;

template<typename T>
void useMatrixTemplate(Matrix<T> & M, T array1[][MAXCOLS], T array2[][MAXCOLS]){
    cout << "Matrix set first array" << endl;
    M.setMatrix(array1);
    M.printMatrix();
    M.addMatrix(array2);
    cout << "\nMatrix incremented by second array" << endl;
    M.printMatrix();
}

int main(){

    string str1[MAXROWS][MAXCOLS] = {{"Congra", "y", "ar"}, "alm", "don", "La"};
    string str2[MAXROWS][MAXCOLS] = {{"tulations", "ou", "e"}, "ost", "e the", "b!"};

    int num1[MAXROWS][MAXCOLS] = {{1,2,3}, {4,5,6}};
    int num2[MAXROWS][MAXCOLS] = {{6,5,4}, {3,2,1}};

    Matrix<string> stringMatrix(2,3);
    Matrix<int> intMax(2,3);

    cout << "Demonstrating with string matrix:" << endl;
    useMatrixTemplate(stringMatrix, str1, str2);

    cout << "\nDemonstrating with int matrix:" << endl;
    useMatrixTemplate(intMax, num1, num2);
    return 0;
}
