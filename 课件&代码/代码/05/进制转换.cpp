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
	int n;
	int a[20], cnt;
	while(scanf("%d", &n)==1) {
		jin(n, 16, a, cnt);
		for(int i=cnt-1; i>=0; i--) {
			if(a[i]>=10) {
				printf("%c", a[i]-10+'A');	// ��10-15ת��'A'-'F' 
			} else {
				printf("%d", a[i]);
			} 
		}
		printf("H\n");
	} 
	
	return 0;
}

