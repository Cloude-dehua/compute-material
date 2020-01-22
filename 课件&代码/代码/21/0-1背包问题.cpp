/**
登登考研团队
*/
#include <cstdio>
const int maxn = 20;
int n, c; // 物品个数和背包容量
int w[maxn], v[maxn];	// 分别代表每个物品的重量和价值 
int b[maxn];	// b[i] == 0 表示物品i不在背包里面 
int e[maxn];	// 最优方案 
int ans;	// 背包最大总价值 
int left;	// 记录搜索过程中背包剩余的容量 
// 尝试讲每个物品装进和拿出背包 
void dfs(int cur) {
	if(cur==n) {	// 已经尝试完毕 
		int cv = 0;	// 表示在当前状态下背包里的物品的总价值 
		for(int i=0; i<n; i++) {
			if(b[i]) cv += v[i];
		}
		if(cv>ans) {	// 发现比ans更大 
			ans = cv;
			for(int i=0; i<n; i++) {	// 记录当前最优的方案 
				e[i] = b[i];
			}
		}
	} else {
		// 每个物品只有两种情况，0表示不在背包中 ,1表示在 
		if(left>=w[cur]) {	// 剩下的容量能装下当前的物品 , 如果如果不能直接不拿 
			left -= w[cur];
			b[cur] = 1;
			dfs(cur+1);
			left += w[cur];	// 回溯 
		} 
		b[cur] = 0;	// 不拿入背包的情况 
		dfs(cur+1);
	}
	
}
int main() {
	while(scanf("%d%d", &n, &c)==2) {
		for(int i=0; i<n; i++) scanf("%d", &w[i]);
		for(int i=0; i<n; i++) scanf("%d", &v[i]);
		ans = 0;
		left = c;
		dfs(0);
		printf("%d\n", ans);
		for(int i=0; i<n; i++) {	// 记录当前最优的方案 
			printf("第%d个物品%s\n",i+1, e[i]>0?"进来":"不在" );
		}
	}
	return 0;
}

