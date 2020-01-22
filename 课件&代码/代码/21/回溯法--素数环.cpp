/**
登登考研团队
*/
#include <cstdio>
#include <cstring>

const int maxn = 20;
int a[maxn];	// 保存排列 
int vis[maxn];
int n;
int primes[maxn*2];
// 判断x是否是素数 
int isPrime(int x) {
	for(int i=2; i<=x/2; i++) {
		if(x%i==0) return 0; 
	}
	return 1;
}
// 构造素数表 
void buildPrimes() {
	for(int i=2; i<maxn*2; i++) {
		primes[i] = isPrime(i);
	}
}
// 1 4 
void dfs(int cur) {
	if(cur==n && primes[a[0]+a[n-1]]) {	// 到达叶子节点 
		for(int i=0; i<n; i++) {
//			if(i!=0) printf(" "); 
			printf("%d ", a[i]);	
		}
		printf("\n");
	} else {
		for(int i=2; i<=n; i++) {	// 尝试 将2~n填入a[cur] 
			if(vis[i]==0 && primes[i+a[cur-1]]) {	// 当前i没有使用 ，检查当前i如果填入会和前面的数之和非素数，冲突 
				a[cur] = i;
				vis[i] = 1;
				dfs(cur + 1);
				vis[i] = 0;	// 回溯 
			}
		}
	}
} 
int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("a.txt", "w", stdout);
	buildPrimes();
	while(scanf("%d", &n) == 1) {
		a[0] = 1;
		memset(vis, 0, sizeof(vis));
		dfs(1);
	}	
	return 0;
}

