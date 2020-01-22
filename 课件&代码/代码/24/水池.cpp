/**
登登考研团队
*/
#include <cstdio>
#include <cstring> 
const int maxn = 110;
int a[maxn][maxn];	// 保存地图 
int vis[maxn][maxn];	// vis[i][j]==0表示顶点(i,j)没有访问 
int dr[] = {-1, 1, 0, 0};	// 方向数组，按上下左右的方向搜索
int dc[] = {0, 0, -1, 1}; 
int n, m;
void dfs(int r, int c) {
	vis[r][c] = 1;	// 访问（r,c）顶点
	// 尝试访问周围没有访问过的水池
	for(int i=0; i<4; i++) {
		int newr = r + dr[i];	
		int newc = c + dc[i];
		if(0<=newr && newr<n && 0<=newc && newc<m 	// 下标没有越界
			&& a[newr][newc]==1	// 是个水池
			&& vis[newr][newc]==0 // 水池没有访问 
		) {
			dfs(newr, newc);	// dfs访问周围的这个水池 
		} 
	} 
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++) {	// 输入 
			for(int j=0; j<m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		memset(vis, 0, sizeof(vis));	//初始化vis数组，表示所有顶点都没有访问 
		int cnt = 0;	// 水池（连通块）的数量 
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j]==1 && vis[i][j]==0) {	// 当前顶点是水池并且没有访问 
					dfs(i,j);	// 从当前顶点出发访问其所在的连通块中的所有水池 
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

