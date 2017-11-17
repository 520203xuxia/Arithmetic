/*#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
using namespace std;
#define N 10//设备数量
#define M 10//车间数量
#define T 1
int C[N + 1], V[N + 1], D[N + 1][M + 1];
string path = "";
void dynamic(int C[N + 1], int V[N + 1], int D[N + 1][M + 1])
{
	int i = 0, j = 0, k = 0;
	//这段代码顺推算出每增加第j号车间其前j-1个车间所分配的设备数D[i][j];
	//以及算出i台设备分配到j个车间的最大利润V[i][j];
	//设备分配给车间
	for (i = 1; i <= M; i++){//车间
		for (int m = 1; m <= N; m++)
		{
			C[m] = rand() % 100;
			cout << "C[" << m << "]=" << C[m] << " ";
		}
		cout << endl;
		for (j = N; j > 0; j--){ //设备
			for (k = 0; k <=j ; k++){ //设备
				if (V[j]<(V[j-k]+C[k])){ //V[j]
					V[j] = V[j - k] + C[k];
					D[j][i] = k;
					
				}
			}
		}
		//D填完一列之后压缩成字符串
		for (int m = 0; m < N; m++)
		{
		}
	}
}
int main(){
		//声明变量以及初始化
		srand((unsigned int)time(0));
		memset(C, 0, sizeof(int));
		memset(V, 0, sizeof(int));
		memset(D, 0, sizeof(int));
		clock_t s, e;
		double time;
		s = clock();
		dynamic(C, V, D);
		e = clock();
		time = (double)(e - s) / CLOCKS_PER_SEC;
		cout << "动态规划，N="<<N<<",M= " << M << "时，最大利润为：" << V[N] << "用时：" << time << endl;
		int k = N;
		for (int j = M; j >= 1; j--){
			cout << "第" << j << "号车间分配了" <<D[k][j] << "台设备。" << endl;
			k =k-D[k][j];
		}
		cout << endl;
		for (int i = 0; i <= N; i++)
		{
			for (int j = 0; j <= M; j++)
				cout << D[i][j] << " ";
			cout << endl;
		}
		return 0;
	}
*/

/*#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
using namespace std;
#define N 10//设备数量
#define M 10//车间数量
#define T 1
int C[N + 1], V[N + 1], D[N + 1];
void dynamic(int C[N + 1], int V[N + 1], int D[N + 1])
{
	int i = 0, j = 0, k = 0;
	//这段代码顺推算出每增加第j号车间其前j-1个车间所分配的设备数D[i][j];
	//以及算出i台设备分配到j个车间的最大利润V[i][j];
	//设备分配给车间
	for (i = 1; i <= M; i++){//车间
		for (int m = 1; m <= N; m++)
		{
			C[m] = rand() % 100;
			cout << "C[" << m << "]=" << C[m] << " ";
		}
		cout << endl;
		for (j = N; j > 0; j--){ //设备
			for (k = 0; k <= j; k++){ //设备
				if (V[j]<(V[j - k] + C[k])){ //V[j]
					V[j] = V[j - k] + C[k];
					D[j] = k;
				}
			}
		}
		//D填完一列之后压缩成字符串
		
	}
}
int main(){
	//声明变量以及初始化
	
	srand((unsigned int)time(0));
	memset(C, 0, sizeof(int));
	memset(V, 0, sizeof(int));
	memset(D, 0, sizeof(int));
	clock_t s, e;
	double time;
	s = clock();*/
	/*dynamic(C, V, D);
	e = clock();
	time = (double)(e - s) / CLOCKS_PER_SEC;
	cout << "动态规划，N=" << N << ",M= " << M << "时，最大利润为：" << V[N] << "用时：" << time << endl;
	int k = N;
	for (int j = M; j >= 1; j--){
		cout << "第" << j << "号车间分配了" << D[k] << "台设备。" << endl;
		k = k - D[k];
	}
	cout << endl;
	*//*
	string path = "";
	for (int i = 0; i < 10000; i++)
	{
		string stra = to_string(i);
		path += stra+" ";
	}	
	cout << path<<endl;
	cout << sizeof(path) << endl;
	return 0;
}*/
