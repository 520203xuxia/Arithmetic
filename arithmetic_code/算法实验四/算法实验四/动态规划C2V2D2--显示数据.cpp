//问题描述：资源分配问题     
//某厂根据计划安排，拟将n台相同的设备分配给m个车间，各车间获得这种设备后，可以为国家提供盈利Ci j(i台设备提供给j号车间将得到的利润，1≤i≤n，1≤j≤m) 。  
//问如何分配，才使国家得到最大的盈利？其中Cij为（0,1000）的随机数。要求输出10个实例  

/*#include<iostream>  
#include<string>  
#include<stdlib.h>  
#include<ctime>  
#include<iomanip>  
using namespace std;
int b[9];
#define N 9//设备数量  
#define M 9//车间数量  
#define T 1
int C[N + 1][M + 1], V[N + 1][M + 1], D[N + 1][M + 1];
int max = 0;
int x[N + 1];
bool test(int *x)
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
		sum += x[i];
	if (sum != N)
		return false;
	else
		return true;
}
void brute(int *x, int t)
{
	int i, j;
	if (t > N)//车间数量
	{
		if (test(x))
		{
			int temp = 0;
			for (j = 1; j <= N; j++)
				temp += C[x[j]][j];
			if (temp > max)
			{
				max = temp;
				for (int k = 1; k <= 9; k++)
				{
					b[k] = x[k];
				}
			}
		}
	}
	else
	{
		for (i = 0; i <= N; i++)
		{
			x[t] = i;
			brute(x, t + 1);
		}
	}
}
void dynamic(int C[N + 1][M + 1], int V[N + 1][M + 1], int D[N + 1][M + 1])
{
	int i = 0, j = 0, k = 0;
	cout << "C[i][j]i台机器分配给j号车间可获得的利润：" << endl;

	for (i = 0; i <= M; i++){
	cout << setw(4) << i;
	}
	cout << endl;
	
	for (i = 1; i <= N; i++){
		cout << setw(4) << i;
		for (j = 1; j <= M; j++){
			C[i][j] = rand() % 100;
			cout << setw(4) << C[i][j];
		}
		cout << endl;
	}
	//////这段代码顺推算出每增加第j号车间其前j-1个车间所分配的设备数D[i][j];  
	//////以及算出i台设备分配到j个车间的最大利润V[i][j];  
	
	//设备分配给车间
	for (i = 1; i <= N; i++){//设备
		for (j = 1; j <= M; j++){//车间
			for (k = 0; k <= i; k++){
				if (V[i][j]<V[k][j - 1] + C[i - k][j]){
					V[i][j] = V[k][j - 1] + C[i - k][j];
					D[i][j] = k;
				}
			}
		}
	}
	
	
}
int main(){
	//  
	int t = T;
	while (t--){
		//声明变量以及初始化  
		srand((unsigned int)time(0));
		//数组c存放i台机器分配给j号车间可获得的利润  
		//数组v存放i台机器分配给前j个车间可获得的最大的利润  
		//数组d存放分配给前j个车间的分配数  

		//初始化数组  
		memset(C, 0, sizeof(int));
		memset(V, 0, sizeof(int));
		memset(D, 0, sizeof(int));
		clock_t s, e;
		double time;
		s = clock();
		dynamic(C, V, D);
		e = clock();
		memset(C, 0, sizeof(int));
		memset(V, 0, sizeof(int));
		memset(D, 0, sizeof(int));

		//从最后一个车间分配的设备数量(N-D[i][j])逆推到第一号车间分配的设备数量。
		cout << "V[i][j]:i台设备分配给前j个车间所获最大利润" << endl;
		int k = N,j,i;
		for (i = 0; i <= M; i++){
			cout << setw(4) << i;
		}
		cout << endl;

		for (i = 1; i <= N; i++){
			cout << setw(4) << i;
			for (j = 1; j <= M; j++){
				cout << setw(4) << V[i][j];
			}
			cout << endl;
		}
		for (j = M; j >= 1; j--){
			cout << "第" << j << "号车间分配了" << k - D[k][j] << "台设备。" << endl;
			k = D[k][j];
		}
		cout << endl;
		time = (double)(e - s) / CLOCKS_PER_SEC;
		cout << "动态规划，最大利润为：" << V[N][M] << "用时：" << time << endl;
		
		brute(x, 1);
		
		for (int k = 9; k >=1; k--)
		{
			cout << "第" << k << "个车间设备：" << b[k] << endl;
		}
		cout << "蛮力法,最大利润：" << max << endl;
	}
	return 0;
}
*/