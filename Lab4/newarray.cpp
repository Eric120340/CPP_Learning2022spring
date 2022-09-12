#include <iostream>
using namespace std;

int main()
{
    //分配内存存储10位整数，将地址分配给指针pArray
    int *pArray = NULL, *t;
    pArray = new int [10];
    if (pArray == NULL)
    {
        cout << "allocation failure.\n" ;
        exit(0);
    }
    //用pArray赋值10个元素给内存
    for (int i = 0; i < 10; i++)
    {
        pArray[i] = 100 + i;
    }

    cout << "Displaying the array content" << endl;
    
    for (t = pArray; t < pArray + 10; t++)
    {
        cout << *t << " ";
    }
    //释放内存
    delete [] pArray;

    return 0;    
    

}