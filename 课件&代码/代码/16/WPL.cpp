#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000;
int w[maxn];	// w[i]表示i结点的权值 
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &w[i]); 
	} 
	sort(w, w+n);	// 对区间w[0, n)升序排序
	int ans = 0;	// 统计合并过程中的结点权值 
	for(int i=0; i<n-1; i++) {	// 进行n-1次合并 
		w[i+1] = w[i] + w[i+1];	// w[i, n) ==> w[i+1, n)
		ans += w[i+1];
		sort(w+i+1, w+n);
	} 
	printf("%d\n", ans);
	return 0;
}

