//������������Դ��������     
//ĳ�����ݼƻ����ţ��⽫n̨��ͬ���豸�����m�����䣬�������������豸�󣬿���Ϊ�����ṩӯ��Ci j(į�豸�ṩ��j�ų��佫�õ�������1��i��n��1��j��m) ��  
//����η��䣬��ʹ���ҵõ�����ӯ��������CijΪ��0,1000�����������Ҫ�����10��ʵ��  

/*#include<iostream>  
#include<string>  
#include<stdlib.h>  
#include<ctime>  
#include<iomanip>  
using namespace std;
int b[9];
#define N 9//�豸����  
#define M 9//��������  
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
	if (t > N)//��������
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
	cout << "C[i][j]į���������j�ų���ɻ�õ�����" << endl;

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
	//////��δ���˳�����ÿ���ӵ�j�ų�����ǰj-1��������������豸��D[i][j];  
	//////�Լ����į�豸���䵽j��������������V[i][j];  
	
	//�豸���������
	for (i = 1; i <= N; i++){//�豸
		for (j = 1; j <= M; j++){//����
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
		//���������Լ���ʼ��  
		srand((unsigned int)time(0));
		//����c���į���������j�ų���ɻ�õ�����  
		//����v���į���������ǰj������ɻ�õ���������  
		//����d��ŷ����ǰj������ķ�����  

		//��ʼ������  
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

		//�����һ�����������豸����(N-D[i][j])���Ƶ���һ�ų��������豸������
		cout << "V[i][j]:į�豸�����ǰj�����������������" << endl;
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
			cout << "��" << j << "�ų��������" << k - D[k][j] << "̨�豸��" << endl;
			k = D[k][j];
		}
		cout << endl;
		time = (double)(e - s) / CLOCKS_PER_SEC;
		cout << "��̬�滮���������Ϊ��" << V[N][M] << "��ʱ��" << time << endl;
		
		brute(x, 1);
		
		for (int k = 9; k >=1; k--)
		{
			cout << "��" << k << "�������豸��" << b[k] << endl;
		}
		cout << "������,�������" << max << endl;
	}
	return 0;
}
*/