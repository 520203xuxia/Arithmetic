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
		//ÿ��ѡ����С������
		for (j = i + 1; j<len; j++)
		{
			if (arr[j]<min)
			{
				min = arr[j];
				index = j;
			}
		}
		//��ѡ�����������η���������
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
	cout << "ѡ������---��������������" << endl;
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
		cout <<"��"<<j<<"��ʱ�䣺"<<time << endl;
		sum += time;
	}
	cout<<"20��������ƽ������ʱ�䣺" << sum / 20 << endl;
	
	return 0;
}