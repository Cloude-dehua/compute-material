#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
// ���������ݵ����Լ��
	return b==0 ? a:gcd(b, a%b);	
}

int main(){
	int a, b;
	while(scanf("%d%d", &a, &b)==2) {
		int m = gcd(a, b);	// ���Լ�� 
		printf("%d %d\n", m, a/m*b);
	}
	return 0;
}

