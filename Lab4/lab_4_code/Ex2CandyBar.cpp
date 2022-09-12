#include <iostream>
#include <string>
using namespace std;

struct CandyBar
{
    char name[21];
    float weight;
    int calories; 
};

int main()
{
    CandyBar *CandyBarArray;
    CandyBarArray = new (nothrow) CandyBar[3];

    cout << "Please input three CandyBar's information: " << endl;
for (int i = 0; i < 3; i++)
{
    cin.sync();
    cout << "Enter the brand name of candy bar: ";
    cin.get(CandyBarArray[i].name,20);
    cout << "Enter the weight: ";
    cin >> CandyBarArray[i].weight;
    cout << "Enter the calories: ";
    cin >> CandyBarArray[i].calories;
    cin.get();
    //cin.clear();
    // 恢复cin正常状态，两个一起使用
    //cin.sync();   //清除缓冲区
    //cin.clear();  //清除错误状态
}

    
    cout << "\nDisplay the CandyBar array contents" << endl;
    for(int i = 0; i < 3; i++)
    {
    cout << "Brand name: " << CandyBarArray[i].name << endl;
    cout << "Weight: " << CandyBarArray[i].weight << endl;
    cout << "Canlories: " << CandyBarArray[i].calories << endl;
    }

    delete [] CandyBarArray;

    return 0;

}