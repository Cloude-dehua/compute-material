#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int a[maxn];

bool cmp(int a, int b) {	// �Զ������������		
	return abs(a) > abs(b);	// ������ֵ�������� 
}
int main(){
	int n;
	while(scanf("%d", &n)==1 && n) {				// ����������� 
		for(int i=0; i<n; i++) scanf("%d", &a[i]);	// �������� 
		sort(a, a+n, cmp);	// ����a[0, n)
		// ��� 
		for(int i=0; i<n; i++) {
			if(i>0) printf(" ");	// ���˵�0�������ⶼ���ȴ�ӡ�ո���������ݣ�����û����β�ո� 
			printf("%d", a[i]);
		} 
		printf("\n");
	}

	return 0;
}

