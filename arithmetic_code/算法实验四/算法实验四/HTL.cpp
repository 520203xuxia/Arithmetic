#include<iostream>
#include<string>
#include<memory>
#include<string>
#include<ctime>
using namespace std;
int n, m, sum;
short C1[100001] = { 0 };
short p[100001] = { 0 };
string D[100001] = { "" };
short DD[100001] = { 0 };
short D_temp;
// �Խ�������ѹ��
void DP4() {
	int i, j, k;
	string b = "";
	for (i = 1; i <= n; i++) {
		if (i == 1) C1[i] = rand() / (RAND_MAX / 100);
		else C1[i] = C1[i - 1] + rand() / (RAND_MAX / 100);
		p[i] = C1[i];
		if (i <= 9) b.append(1, 'a' + i);
		else if (10 <= i&&i <= 99) {
			string s = "T";
			s.append(to_string(i));
			string s1(s.rbegin(), s.rend());
			b.append(s1);
		}
		else if (100 <= i&&i <= 999) {
			string s = "t";
			s.append(to_string(i));
			string s1(s.rbegin(), s.rend());
			b.append(s1);
		}
		else if (1000 <= i&&i <= 9999) {
			string s = "0";
			s.append(to_string(i));
			string s1(s.rbegin(), s.rend());
			b.append(s1);
		}
		else if (10000 <= i&&i <= 99999) {
			string s = "";
			s.append(to_string(i));
			string s1(s.rbegin(), s.rend());
			b.append(s1);
		}
		else b.append(1, 'a' + 10);
	}//cout << endl;
	
	string s(b.rbegin(), b.rend());
	D[1] = s;

	for (j = 2; j <= m; j++) {
		if (j % 1000 == 0) cout << j << endl;

		for (i = 1; i <= n; i++) {
			if (i == 1) C1[i] = rand() / (RAND_MAX / 100);
			else C1[i] = C1[i - 1] + rand() / (RAND_MAX / 100);
			//cout << C1[i] << " ";
			//C1[i] = C[i][j];
		}//cout << endl;

		for (i = n; i > 0; i--) {
			b = ""; D_temp = 0;
			for (k = i - 1; k >= 0; k--) {
				if (p[i] < p[k] + C1[i - k]) {
					p[i] = p[k] + C1[i - k];
					D_temp = i - k;
				}
				/*p[i] = max(p[i], p[k] + C1[i - k]);
				if (p[i] == p[i] + C1[i - k]) D_temp = i - k;*/
			}
			b = "";
			if (D_temp <= 9) b.append(1, 'a' + D_temp);
			else if (10 <= D_temp&&D_temp <= 99) { b.append("T").append(to_string(D_temp)); }
			else if (100 <= D_temp&&D_temp <= 999) { b.append("t").append(to_string(D_temp)); }
			else if (1000 <= D_temp&&D_temp <= 9999) { b.append("0").append(to_string(D_temp)); }
			else if (10000 <= D_temp&&D_temp <= 99999) { b.append(to_string(D_temp)); }
			else b.append(1, 'z');
			D[j].append(b);
			if (j == m) break;
		}
		//cout << endl;
		//cout << numOfDist[j] << endl;
	}
	/*
	int lest;
	for (lest = n, j = m; j > 0 && lest >= 1; j--) {
		int i = 0, ii = 0;
		while (ii++ != n - lest) {
			if (D[j][i] > 'a' + 10 || D[j][i] < 'a') {
				if (D[j][i] == 'T') i = i + 2;
				else if (D[j][i] == 't') i = i + 3;
				else i = i + 4;
			}
			i++;
		}
		if (D[j][i] >= 'a'&&D[j][i] <= 'a' + 10) {
			if (D[j][i] == 'a' + 10) DD[j] = n;
			else DD[j] = D[j][i] - 'a';
		}
		else if (D[j][i] == 'T') {
			int num = 0;
			i++;
			num = num * 10 + D[j][i++] - '0';
			num = num * 10 + D[j][i++] - '0';
			DD[j] = num;
		}
		else if (D[j][i] == 't') {
			int num = 0;
			i++;
			num = num * 10 + D[j][i++] - '0';
			num = num * 10 + D[j][i++] - '0';
			num = num * 10 + D[j][i++] - '0';
			DD[j] = num;
		}
		else {
			int num = 0;
			num = num * 10 + D[j][i++] - '0';
			num = num * 10 + D[j][i++] - '0';
			num = num * 10 + D[j][i++] - '0';
			num = num * 10 + D[j][i++] - '0';
			num = num * 10 + D[j][i++] - '0';
			DD[j] = num;
		}
		D[j] = "";
		lest = lest - DD[j];
	}*/
}

int main()
{
	srand((unsigned)time(NULL));
	time_t timeBegin, timeEnd;

	cout << "�������豸���͹�����:";
	cin >> n >> m;

	sum = 0;
	timeBegin = clock();
	DP4();
	timeEnd = clock();
	cout << "��̬�滮3����ʱ:" << timeEnd - timeBegin << "ms" << endl;
	cout << "��̬�滮3�����������Ϊ" << p[n] << endl;
	/*for (int i = 1; i <= m; i++) {
	cout << DD[i] << " ";
	u += DD[i];
	//cout << "��" << i << "��������" << DD[i] << "���豸 \n";
	}cout << endl << endl;*/

	return 0;
}