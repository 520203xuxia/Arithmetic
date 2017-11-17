#include<iostream>
#include<cmath>
#include<algorithm>
#include<time.h>
using namespace std;
bool brute_test(int a[8][2])
{
	int i, j,k;
	for (i = 1; i < 8; i++)
	{
		k = i;
		for (j = i-1; j >= 0; j--)
		{
			if (a[k][0] == a[j][0] || a[k][1] == a[j][1] || (double)((a[k][0] - a[j][0])) / (double)((a[k][1] - a[j][1])) == 1 || (double)((a[k][0] - a[j][0])) / (double)((a[k][1] - a[j][1])) == -1)
			{
				return false;
			}
		}
	}
	return true;
}

int main(){
	while (true)
	{
		cout << "请输入你要测试的数据" << endl;
		int a[8][2],i,j;
		for (i = 0; i < 8;i++)
		for (j = 0; j < 2; j++)
			cin >> a[i][j];
		if (brute_test(a))
			cout << "满足八皇后要求" << endl;
		else
			cout << "不满足八皇后要求" << endl;
		
	}
}