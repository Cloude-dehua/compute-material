#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int n;
	while(scanf("%d", &n)==1) {
		int m=0;
		int tmp = n;
		while(tmp>0) {
			m = m*10 + tmp%10;		// ��ǰ��λ���ϸ�λ 
			tmp /= 10;				// ������λ 
		}
		if(m%n==0) {	// �������� 
			printf("%d*%d=%d\n", n, m/n, m);
		} else {
			printf("%d ", n);
			// ��ӡm��ǰ��0
			tmp = n;
			while(tmp>10 && tmp%10==0) {	// �ж�n�ĵ�λ�м����� 
				printf("0");
				tmp /= 10;	
			} 
			printf("%d\n", m);
		}
		
	}

	return 0;
}

