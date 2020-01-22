#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 25;
int flag[maxn];

void shu(int& a, int t, int d, int n) {
// ��a������d������t��
	while(t--) {	// ��t�� 
		do{			// ��һ�� 
			a += d;	// ����d������ 
			if(a>n) a = 1;	// �ж����� 
			if(a<1) a = n;
		} while(flag[a]);		// flag[a]==1��ʾa��ָ����˲��ڶ������棬��һ�����㣬������ 
	}	
}
int main(){
	int n, k, m;
	while(scanf("%d%d%d", &n, &k, &m)==3) {
		memset(flag, 0, sizeof(flag));	// ��ʼ��Ϊ0��ʾȫ���ڶ������� 
		int a = n, b = 1;	// ��ʼ����ָλ��
		int left = n;		// ������ʣ�����
		while(left>0) {		// �����ﻹ���� 
			shu(a, k, 1, n);	// a��С������ 
			shu(b, m, -1, n);	// b�Ӵ���С�� 
			flag[a] = flag[b] = 1;	// �����˳��ӣ����߼�ɾ�� 
			if(a==b) {
				printf("%d", a);	// ָ��ͬһ���� 
				left--;
			} else {	// ָ��ͬ���� 
				printf("%d %d", a, b); 
				left -= 2;
			}
			if(left) printf(",");	// ���ŷָ�һ��ѭ�� 
			else printf("\n");
		} 
	}

	return 0;
}

