#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 15;
char map[maxn][maxn];
int vis[maxn][maxn];		// vis[i][j] 标记结点(i, j)是否访问 
int n, m;
void dfs(int r, int c) {
// 深度优先遍历结点（r,c）所在的连通块	
	vis[r][c] = 1;		// 标记访问 
	for(int i=-1; i<=1; i++) {
		for(int j=-1; j<=1; j++) {
			if(0<=r+i&&r+i<n && 0<=c+j && c+j<m		// 下标不越界 
			&& vis[r+i][c+j]==0						// 没有访问 
			&& map[r+i][c+j]=='@') {					// 是@字符	
				dfs(r+i, c+j);
			} 
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%s", map[i]);
	}
	
	memset(vis, 0, sizeof(vis));		// 初始化
	int ans = 0;						// 记录连通块数量 
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!vis[i][j] && map[i][j]=='@') {	// 结点(i,j)是一个没有访问过的@ 
				dfs(i, j);						// 从她开始遍历连通块中所有的@ 
				ans++;
			}
		}
	} 
	printf("%d\n", ans); 
	return 0;
}

