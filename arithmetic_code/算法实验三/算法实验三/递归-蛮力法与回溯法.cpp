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
//���ݷ�--��֦--�ݹ�
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
//������--�ݹ�-����֦
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
		cout << "����ģn��" << n << endl;
		x = new int[n];
		double time_brute,time;
		clock_t start, end;
		start = clock();
		Backtrack_brute(1, n, x);//����֦--������
		end = clock();
		time_brute=(double)(end - start) / CLOCKS_PER_SEC;

		start = clock();
		Backtrack(1, n, x);//��֦	
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		cout <<"�ݹ�-����-�������"<< sum <<"���������Ϊ��"<<knot<<"��ʱ"<<time<<"s"<< endl;
		cout << "�ݹ�-����-�������" << sum_brute << "���������Ϊ��" << knot_brute <<"��ʱ"<<time_brute<<"s"<< endl;
		outfile.open("answer.txt",ios::app);

		outfile_brute.open("answer_brute.txt", ios::app);
		outfile << "n=" << n << "ʱ����Ϊ��"<<endl;
		outfile_brute << "n=" << n << "ʱ����Ϊ��" << endl;
		//������д���ļ���
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
