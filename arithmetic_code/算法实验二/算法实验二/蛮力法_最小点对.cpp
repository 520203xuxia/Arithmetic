/*#include<iostream>
#include<random>
#include<ctime>
using namespace std;
int main()
{
	
	int n,i,j;
	cout << "请输入您要计算的点的数量：" << endl;
	cin >> n;
	double **XY = new double *[n];
	for (i = 0; i < n; i++)
		XY[i] = new double[2];
	srand(unsigned(time(0)));
	double a = 0, b = 65535;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2; j++)
			XY[i][j] = (double)rand() / RAND_MAX * (b - a) + a;
	}
	double min = 99999.0,temp;
	double x1, y1, x2, y2;
	clock_t start = clock();
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			temp =sqrt((XY[i][0] - XY[j][0])*(XY[i][0] - XY[j][0]) +
				(XY[i][1] - XY[j][1])*(XY[i][1] - XY[j][1]));
			if (temp < min&&temp!=0)
			{
				min = temp;
				x1 = XY[i][0];
				y1 = XY[i][1];
				x2 = XY[j][0];
				y2 = XY[j][1];
			}
				
		}
	}
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
	cout << "运行时间为：" << time << "ms\n最小点对为：\n" 
		<< x1 << " " << y1 << "\n" << x2 << " " << y2 << endl;
	cout<< "最小距离为："<<min << endl;
}*/