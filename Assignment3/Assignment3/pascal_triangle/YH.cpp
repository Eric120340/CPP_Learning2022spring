#include <iostream>
using namespace std; 
int n;
int main()
{
	cin>>n;
	int a[n][n];
	for (int i=0;i<n;i++)
	a[i][0]=1;
	for (int i=0;i<n;i++)
	a[i][i]=1;
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<i;j++)//j<i是 因为a[n][n] 全是1了；j=0那一竖排也全是1； 
		a[i][j]=a[i-1][j-1]+a[i-1][j];//这句话是 重点！！！ 
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<i+1;j++)
		cout <<a[i][j]<<" ";
		cout <<endl;
	}
    cout << endl;
	cout << a[0][0] << endl;

    return 0;
}

