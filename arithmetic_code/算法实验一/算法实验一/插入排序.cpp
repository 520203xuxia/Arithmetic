#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
void insert_sort(int arr[], int len){
	//����n-1�����ݣ�ѭ��n-1��          cost  times
	for (int j = 1; j<len; j++) //       c1     n  
	{
		int key = arr[j];     //         c2    n-1
		int i = j - 1;//				 c3    n-1
		//�ҵ���������ֵĺ���λ��
		while (i >= 0 && arr[i]>key) //  c4    ��tj��j=2 to j=n)
		{
			arr[i + 1] = arr[i];//       c5	   ��(tj-1)��j=2 to j=n)
			i--;				//       c6	   ��(tj-1)��j=2 to j=n)
		}
		arr[i + 1] = key;//				 c7    n-1
	}
}

int main()
{
int n, i,j=0;
double sum = 0;
int t = 20;
cout << "��������---��������������" << endl;
cin >> n;
while (t--)
{
j++;
int *arr;
arr = new int[n];
for (i = 0; i<n; i++)
	arr[i] = rand();
clock_t start = clock();
insert_sort(arr, n);
clock_t end = clock();
double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
cout <<"��"<<j<<"��ʱ�䣺"<<time << endl;
sum += time;
}
cout<<"20��������ƽ������ʱ�䣺" << sum / 20 << endl;

return 0;
}