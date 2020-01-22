#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;	// 问题规模 
int a[maxn];				// 数组，通常定义为全局变量 
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	memset(a, 0, sizeof(a));		// 初始化，它只能初始化为0或者-1，如果想要初始化为其他数据，用for循环 
	for(int i=1; i<=k; i++) {		// 模拟k个人 
		for(int j=i; j<=n; j+=i) {	// 第i个人来操作这些i的倍数的灯泡 
			a[j] = !a[j];			// 改变开关状态 
		}
	} 
	for(int i=1; i<=n; i++) {		// 输出 
		if(a[i]) printf("%d ", i); 	
	} 
	
	return 0;
}

