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
vector<int> an,an_brute;
long long sum = 0;//递归的解的个数
long long sum_solve = 0;//非递归的解的个数

bool Place(int k, int *x)//检查前k行是否合法
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
//回溯法--剪枝--递归
void Backtrack(int t, int n, int *x)
{
	if (t>n)
	{
		sum++;
		for (int i = 1; i <= n; i++)
			an.push_back(x[i]);
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			x[t] = i;
			if (Place(t, x))
				Backtrack(t + 1, n, x);			
		}
	}
}
bool isValid(vector<int>x, int r, int c)
{
	if (x.empty())
		return true;
	for (int i = 0; i < r; i++)
	{
		if (x[i] == c || abs(i - r) == abs(x[i] - c))
			return false;
	}
	return true;
}
//非递归
void solve(int n)
{
	int i, j;
	vector<int>x(n, -1);
	i = 0; j = 0;
	while (i < n)
	{
		while (j < n)
		{
			if (isValid(x, i, j))
			{
				x[i] = j;
				j = 0;
				break;
			}
			else
				++j;
		}
		if (-1 == x[i])//第i+1行没有找到合适的位置
		{
			if (0 == i)
				break;
			else
			{
				--i;
				j = x[i] + 1;
				x[i] = -1;
				continue;
			}
		}
		//找到解
		if (i == n - 1)
		{
			sum_solve++;
			for (int k = 0; k < n; k++)
				an.push_back(x[k]);
			j = x[i] + 1;
			x[i] = -1;
			continue;
		}
		++i;
	}
}
int main()
{
	int n=4;
	while (n<18)
	{
		cout << "求解规模n：" <<n<< endl;
		x = new int[n];
		double  time,time_solve;
		clock_t start, end;
		start = clock();
		Backtrack(1, n, x);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		start = clock();
		solve(n);
		end = clock();
		time_solve = (double)(end - start) / CLOCKS_PER_SEC;		
		cout << "递归-剪枝-用时：" << time <<"解的个数："<<sum<< endl;
		cout << "非递归-剪枝-用时：" << time_solve << "解的个数：" << sum_solve << endl;
		cout << endl;
		sum = 0;
		sum_solve = 0;
		n++;
	}
}