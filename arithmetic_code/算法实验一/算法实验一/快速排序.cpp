#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
void quick_sort(int arr[],int l,int r){
	if (l < r)
	{
		int i = l, j = r, x = arr[l];
		//对子数组进行排序
		while (i < j)
		{
			while (i < j && arr[j] >= x)
				j--;
			if (i < j)
				arr[i++] = arr[j];
			while (i < j && arr[i] < x)
				i++;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = x;
		//将数组拆分成子数组进行求解
		quick_sort(arr, l, i - 1);
		quick_sort(arr, i + 1, r);
	}
}
int main()
{
	int n, i, j = 0;
	double sum = 0;
	int t = 20;
	cout << "快速排序---请输入数据量：" << endl;
	cin >> n;
	while (t--)
	{
		j++;
		int *arr;
		arr = new int[n];

		for (i = 0; i<n; i++)
			arr[i] = rand();
		clock_t start = clock();
		quick_sort(arr, 0,n-1);
		clock_t end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
		cout << "第" << j << "组时间：" << time << endl;
		sum += time;
	}
	cout << "20个样本的平均运行时间：" << sum / 20 << endl;

	return 0;
}