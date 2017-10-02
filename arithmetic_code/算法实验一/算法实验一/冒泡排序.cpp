#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
void bubble_sort(int arr[], int len)
{
	int i, j, temp;
	for (i = 0; i<len-1; i++)//循环n-1次
	{
		for (j = 0; j<len - 1-i; j++)
		{
			if (arr[j]>arr[j + 1])//将较大的数字往后移
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				
			}
		}
	}
}


int main()
{
	int n, i, j = 0;
	double sum = 0;
	int t = 20;
	cout << "冒泡排序---请输入数据量：" << endl;
	cin >> n;
	while (t--)
	{
		j++;
		int *arr;
		arr = new int[n];
		for (i = 0; i<n; i++)
			arr[i] = rand();
		clock_t start = clock();
		bubble_sort(arr, n);
		clock_t end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
		cout << "第" << j << "组时间：" << time << endl;
		sum += time;
	}
	cout << "20个样本的平均运行时间：" << sum / 20 << endl;

	return 0;
}
