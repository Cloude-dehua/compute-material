#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
void jin(int n, int k, int* a, int& cnt) {
// ��ʮ����������nת��Ϊk���ƺ󱣴�������a��,cnt��ʾ����ж���λ��ͨ�����ÿ�����ʵ���õ��βε�ֵ�� 
	cnt = 0;
	if(n==0) {		// n����0��ת�����һ���� 
		a[cnt++] = 0;	
	}
	while(n>0) {	// ģ��̳���������һֱ��ѭ�� 
		a[cnt++] = n % k;		// ������
		n /= k;					// ���� 
	}	
}

int main(){
	int k, a, b;
	int num[20], cnt;
	while(scanf("%d%d%d", &k, &a, &b)==3 && k) {
		jin(a+b, k, num, cnt);
		for(int i=cnt-1; i>=0; i--) {	// �������λ 
			printf("%d", num[i]);
		}
		printf("\n");
	}	

	return 0;
}

