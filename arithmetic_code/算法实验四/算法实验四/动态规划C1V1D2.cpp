/*#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
using namespace std;
#define N 10//�豸����
#define M 10//��������
#define T 1
int C[N + 1], V[N + 1], D[N + 1][M + 1];
string path = "";
void dynamic(int C[N + 1], int V[N + 1], int D[N + 1][M + 1])
{
	int i = 0, j = 0, k = 0;
	//��δ���˳�����ÿ���ӵ�j�ų�����ǰj-1��������������豸��D[i][j];
	//�Լ����į�豸���䵽j��������������V[i][j];
	//�豸���������
	for (i = 1; i <= M; i++){//����
		for (int m = 1; m <= N; m++)
		{
			C[m] = rand() % 100;
			cout << "C[" << m << "]=" << C[m] << " ";
		}
		cout << endl;
		for (j = N; j > 0; j--){ //�豸
			for (k = 0; k <=j ; k++){ //�豸
				if (V[j]<(V[j-k]+C[k])){ //V[j]
					V[j] = V[j - k] + C[k];
					D[j][i] = k;
					
				}
			}
		}
		//D����һ��֮��ѹ�����ַ���
		for (int m = 0; m < N; m++)
		{
		}
	}
}
int main(){
		//���������Լ���ʼ��
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
		cout << "��̬�滮��N="<<N<<",M= " << M << "ʱ���������Ϊ��" << V[N] << "��ʱ��" << time << endl;
		int k = N;
		for (int j = M; j >= 1; j--){
			cout << "��" << j << "�ų��������" <<D[k][j] << "̨�豸��" << endl;
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
#define N 10//�豸����
#define M 10//��������
#define T 1
int C[N + 1], V[N + 1], D[N + 1];
void dynamic(int C[N + 1], int V[N + 1], int D[N + 1])
{
	int i = 0, j = 0, k = 0;
	//��δ���˳�����ÿ���ӵ�j�ų�����ǰj-1��������������豸��D[i][j];
	//�Լ����į�豸���䵽j��������������V[i][j];
	//�豸���������
	for (i = 1; i <= M; i++){//����
		for (int m = 1; m <= N; m++)
		{
			C[m] = rand() % 100;
			cout << "C[" << m << "]=" << C[m] << " ";
		}
		cout << endl;
		for (j = N; j > 0; j--){ //�豸
			for (k = 0; k <= j; k++){ //�豸
				if (V[j]<(V[j - k] + C[k])){ //V[j]
					V[j] = V[j - k] + C[k];
					D[j] = k;
				}
			}
		}
		//D����һ��֮��ѹ�����ַ���
		
	}
}
int main(){
	//���������Լ���ʼ��
	
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
	cout << "��̬�滮��N=" << N << ",M= " << M << "ʱ���������Ϊ��" << V[N] << "��ʱ��" << time << endl;
	int k = N;
	for (int j = M; j >= 1; j--){
		cout << "��" << j << "�ų��������" << D[k] << "̨�豸��" << endl;
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
