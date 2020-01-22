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

bool cmp(int a, int b) {	// 自定义排序规则函数		
	return abs(a) > abs(b);	// 按绝对值降序排序 
}
int main(){
	int n;
	while(scanf("%d", &n)==1 && n) {				// 处理多组数据 
		for(int i=0; i<n; i++) scanf("%d", &a[i]);	// 输入数据 
		sort(a, a+n, cmp);	// 排序a[0, n)
		// 输出 
		for(int i=0; i<n; i++) {
			if(i>0) printf(" ");	// 除了第0个数据外都是先打印空格在输出数据，这样没有行尾空格 
			printf("%d", a[i]);
		} 
		printf("\n");
	}

	return 0;
}

