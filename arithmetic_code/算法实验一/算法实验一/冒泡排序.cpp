#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
void bubble_sort(int arr[], int len)
{
	int i, j, temp;
	for (i = 0; i<len-1; i++)//ѭ��n-1��
	{
		for (j = 0; j<len - 1-i; j++)
		{
			if (arr[j]>arr[j + 1])//���ϴ������������
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
	cout << "ð������---��������������" << endl;
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
		cout << "��" << j << "��ʱ�䣺" << time << endl;
		sum += time;
	}
	cout << "20��������ƽ������ʱ�䣺" << sum / 20 << endl;

	return 0;
}
