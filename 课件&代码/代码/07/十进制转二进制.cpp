#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
void jin(int n, int k, int* a, int& len) {
// ��ʮ���ƷǸ�����nת��Ϊk���Ʊ�����a�У�ת������lenλ
	if(n==0) {
		a[0] = 0;
		len = 1;
		return;
	}
	len = 0;
	while(n>0) {	// ����0��ģ��̳��� 
		a[len++] = n%k;		// �õ����� 
		n /= k;				// �õ��� 
	}	
}

int main(){
	int n;
	while(scanf("%d", &n)==1) {
//		int a[100], len;
//		jin(n, 2, a, len);
//		for(int i=len-1; i>=0; i--) {	// �Ӹߵ�λ���ÿһλ 
//			printf("%d", a[i]);
//		} 
	
		// ���߼���Ӹߵ���ȡ��ÿλ�������� 
		int first = 1;	// ����Ƿ�Ϊǰ���� 
		for(int i=31; i>=0; i--) {
			if(n & 1<<i) {
				printf("1");
				first = 0;		// ��Ǻ������Ϊ��ǰ���� 
			} else {
				if(!first) 
					printf("0");
			}
		} 
	
		printf("\n");
	} 

	return 0;
}

