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
	// 判断x1*x3*x4*...xk/x2是否为整数
	x[2] = x[2]/gcd(x[1], x[2]);
	for(int i=3; i<k; i++) {
		x[2] /= gcd(x[i], x[2]);		// 用分子中每一项和分母约分
		if(x[2]==1) break;				// x2已经是一了，即约分完成，整个分母是1 
	} 
	if(x[2]==1) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}

