#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int gcd(int a, int b) {
	return b==0?a:gcd(b, a%b);
}
const int maxn = 10000 + 10;
int x[maxn];
int main(){
	int k = 1;
	while(scanf("%d", &x[k])==1) {
		k++;
	}
	// �ж�x1*x3*x4*...xk/x2�Ƿ�Ϊ����
	x[2] = x[2]/gcd(x[1], x[2]);
	for(int i=3; i<k; i++) {
		x[2] /= gcd(x[i], x[2]);		// �÷�����ÿһ��ͷ�ĸԼ��
		if(x[2]==1) break;				// x2�Ѿ���һ�ˣ���Լ����ɣ�������ĸ��1 
	} 
	if(x[2]==1) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}

