#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 25;
int G[maxn][maxn];		// 图的邻接矩阵 G[i][j]==1表示i和j顶点有一条边 
int vis[maxn];			// vis[i]标记结点i是否访问 
int n, m;
int cnt = 0;	// 记录遍历过的结点数量 
void dfs(int u) {
	vis[u] = 1;		// 访问当前顶点
	cnt++;
	for(int i=1; i<=n; i++) {			// 尝试访问周围没有访问过的邻居结点 
		if(G[i][u]==1 && !vis[i]) {
			dfs(i);
		}
	} 
} 


int main(){

	while(scanf("%d%d", &n, &m)==2) {
		int a, b;		// 接收边（a,b） 
		memset(G, 0, sizeof(G));	// 初始化G 
		for(int i=0; i<m; i++) {	// 接收m条边 
			scanf("%d%d", &a, &b);
			G[a][b] = G[b][a] = 1;		// 无向图的邻接矩阵是个对称矩阵 
		}
		if(m==n-1) {	// 生成树的边的数量等于顶点数量减一 
			memset(vis, 0, sizeof(vis));		// 初始化vis数组
			cnt = 0;
			dfs(1);		// 从顶点1，开始遍历
			if(cnt==n) {	// 遍历了n个结点，图的连通的,是生出树 
				printf("YES\n"); 
			} else {
				printf("NO\n");
			}
		} else {
			printf("NO\n");
		}
	} 

	return 0;
}

