#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
void select_sort(int arr[], int len){
	int min, i, j, index, temp;
	for (i = 0; i<len-1; i++)
	{
		min = arr[i];
		index = i;
		//每次选出最小的数字
		for (j = i + 1; j<len; j++)
		{
			if (arr[j]<min)
			{
				min = arr[j];
				index = j;
			}
		}
		//将选出的数字依次放入数组中
		if (index != i)
		{
			temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;
		}
	}
}

int main()
{
	int n, i,j=0;
	double sum = 0;
	int t = 20;
	cout << "选择排序---请输入数据量：" << endl;
	cin >> n;
	while (t--)
	{
		j++;
		int *arr;
		arr = new int[n];

		for (i = 0; i<n; i++)
			arr[i] = rand();
		clock_t start = clock();
		select_sort(arr, n);
		clock_t end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
		cout <<"第"<<j<<"组时间："<<time << endl;
		sum += time;
	}
	cout<<"20个样本的平均运行时间：" << sum / 20 << endl;
	
	return 0;
}