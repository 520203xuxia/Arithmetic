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
long long sum = 0;
long long sum_brute = 0;
long long knot = 0;
long long knot_brute = 0;
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
			knot++;
			if (Place(t, x))
				Backtrack(t + 1, n, x);
		}
	}
}
//蛮力法--递归-不剪枝
void Backtrack_brute(int t, int n, int *x)
{
	if (t>n)
	{
		if (brute_test(x, n))
		{
			sum_brute++;
			for (int i = 1; i <= n; i++)
			   an_brute.push_back(x[i]);
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			x[t] = i;
			knot_brute++;
			Backtrack_brute(t + 1, n, x);
		}
	}
}

int main()
{
	int n = 4;
	while (n<18)
	{
		cout << "求解规模n：" << n << endl;
		x = new int[n];
		double time_brute,time;
		clock_t start, end;
		start = clock();
		Backtrack_brute(1, n, x);//不剪枝--蛮力法
		end = clock();
		time_brute=(double)(end - start) / CLOCKS_PER_SEC;

		start = clock();
		Backtrack(1, n, x);//剪枝	
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		cout <<"递归-回溯-解个数："<< sum <<"遍历结点数为："<<knot<<"用时"<<time<<"s"<< endl;
		cout << "递归-蛮力-解个数：" << sum_brute << "遍历结点数为：" << knot_brute <<"用时"<<time_brute<<"s"<< endl;
		outfile.open("answer.txt",ios::app);

		outfile_brute.open("answer_brute.txt", ios::app);
		outfile << "n=" << n << "时，解为："<<endl;
		outfile_brute << "n=" << n << "时，解为：" << endl;
		//将解结果写入文件中
		for (int i = 0; i < an.size(); i++)
		{
			if ((i + 1) % (an.size() / sum) != 0)
			{
				outfile << an[i] << ' ';
				outfile_brute << an[i] << ' ';
			}
			else
			{
				outfile << an[i] << endl;
				outfile_brute << an[i] << endl;
			}
		}
		cout << endl;
		knot = 0;
		knot_brute = 0;
		sum = 0;
		sum_brute = 0;
		an.clear();
		an_brute.clear();
		outfile.close();
		outfile_brute.close();
		n++;
	}
}
