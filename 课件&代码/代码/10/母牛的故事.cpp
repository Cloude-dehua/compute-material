#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 60;
ll a[maxn];				// a[i]�����i��ţ������ 

int main(){
	// ���ÿһ��ţ������ a[i] = a[i-1] + a[i-3];	// ��һ��ͷȫ����������ǰ�����ţ����һ�궼������һͷţ
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	for(int i=4; i<maxn; i++) {		// ��ʼ��a���� 
		a[i] = a[i-1]+a[i-3];
	} 
	int n;
	while(scanf("%d", &n)==1 && n) {
		printf("%d\n", a[n]);
	} 
	return 0;
}

