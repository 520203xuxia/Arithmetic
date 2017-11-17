#include<iostream>
#include<cmath>
#include<algorithm>
#include <vector>
#include <fstream>
#include<time.h>
using namespace std;
ofstream outfile;
ofstream outfile_brute;
int *x;
vector<int> an, an_brute;
long long sum_nondigui = 0;
long long sum_digui = 0;

bool Place(int k, int *x)//���ǰk���Ƿ�Ϸ�
{
	for (int j = 1; j < k; j++)
	{
		if ((abs(k - j) == abs(x[j] - x[k])) || x[j] == x[k])
			return false;
	}
	return true;
}
bool brute_test(int *x, int n)
{
	int i, j, k;
	for (i = 2; i <= n; i++)
	if (!Place(i, x))
		return false;
	return true;
}
//������--�ݹ�-����֦
void Backtrack_brute(int t, int n, int *x)
{
	if (t>n)
	{
		if (brute_test(x, n))
		{
			sum_digui++;
			
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			x[t] = i;
			
			Backtrack_brute(t + 1, n, x);
		}
	}
}
bool check(int *p, int n)
{
	int i, j, k;
	for (i = 2; i <= n; i++)
	if (!Place(i, p))
		return false;
	return true;
}
//������--�ǵݹ�-����֦
void solve(int n)
{
	int i = 1;
	int *p = new int[n + 1];
	p[i] = 1;
	while (i > 0)
	{
		if (i <= n&&p[i] <= n)
		{
			i++;
			p[i] = 1;
		}
		else
		{
			if (i>n && (check(p, n) == true))
				sum_nondigui++;
			i--;
			p[i]++;
		}
	}
}
int main()
{
	int n = 4;
	while (n<18)
	{
		cout << "����ģn��" << n << endl;
		x = new int[n];
		Backtrack_brute(1, n, x);//����֦--������--�ݹ�

		solve(n);//����֦--������--�ǵݹ�		
		cout << "������--�ݹ飺" << sum_digui << endl;
		cout << "������--�ǵݹ飺" << sum_nondigui << endl;
		cout << endl;
		
		sum_digui = 0;
		sum_nondigui = 0;
		
		n++;
	}
}