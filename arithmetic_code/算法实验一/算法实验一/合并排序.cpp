#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
void merge(int arr[],int l,int m,int r)
{
	int x1 = m - l + 1;
	int x2 = r - m;
	int *L = new int[x1 + 1];
	int *R = new int[x2 + 1];
	int i, j, k;

	for (i = 0; i < x1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < x2; j++)
		R[j] = arr[m + j + 1];
	L[x1] = 999999;
	R[x2] = 999999;
	for (i = 0, j = 0, k = l; k <= r; k++)//�ϲ�����������
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
	}
	delete[]L;
	delete[]R;
}
void merge_sort(int arr[], int l,int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		merge_sort(arr, l, m);//�ݹ齫�������ֳ�С����������
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);//������õ�������ϲ�
	}
}

int main()
{
	int n, i, j = 0;
	double sum = 0;
	int t = 20;
	cout << "�ϲ�����---��������������" << endl;
	cin >> n;
	while (t--)
	{
		j++;
		int *arr;
		arr = new int[n];
		for (i = 0; i<n; i++)
			arr[i] = rand();		
		clock_t start = clock();
		merge_sort(arr, 0,n-1);
		clock_t end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
		cout << "��" << j << "��ʱ�䣺" << time << endl;
		sum += time;
	}
	cout << "20��������ƽ������ʱ�䣺" << sum / 20 << endl;

	return 0;
}
