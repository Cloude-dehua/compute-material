#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000+10;
int a[maxn];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n);	// 升序排序区间a[0, n)的值
	int ans = 0;
	for(int i=0; i<n-1; i++) {	// 经过n-1合并 
		a[i+1] = a[i]+a[i+1];	// 选择子升序区间a[i, n)中选择最前两堆进行合并放入a[i+1] 
		ans += a[i+1];
		sort(a+i+1, a+n);	// 升序排序区间a[i+1, n)的值
	} 
	printf("%d\n", ans);
	return 0;
}

