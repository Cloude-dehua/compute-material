#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 60;
ll a[maxn];				// a[i]保存第i年牛的数量 

int main(){
	// 算出每一年牛的数量 a[i] = a[i-1] + a[i-3];	// 上一年头全部活下来，前三年的牛到这一年都会生出一头牛
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	for(int i=4; i<maxn; i++) {		// 初始化a数组 
		a[i] = a[i-1]+a[i-3];
	} 
	int n;
	while(scanf("%d", &n)==1 && n) {
		printf("%d\n", a[n]);
	} 
	return 0;
}

