#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 10;
char G[maxn][maxn];		// 地图 
int vis[maxn][maxn];	// vis[i][j]==1表示顶点(i, j)已经被访问
int dr[] = {-1, 1, 0, 0};	// r的搜索方向:上下左右 
int dc[] = {0, 0, -1, 1};
int n, m, t;
bool bfs(int r, int c) {
// 从顶点(r,c)开始搜索
	memset(vis, 0, sizeof(vis));	// 初始化vis数组
	vis[r][c] = 1;	// 访问(r,c)
	queue<int> q;		// 保持真正访问的结点的编码
	 // 编码:drc r在十位，c在个位
	q.push(0*100+r*10+c);	// 将初始结点'S'的编码加入队列
	while(!q.empty()) {
	 	int u = q.front();	// 访问队头元素
		q.pop();			// 弹出队首元素
		// 解码
		int ur = u/10%10;	// 十位
		int uc = u%10;		// 个位
		int ud = u/100;		// 百位及其以上
		if(G[ur][uc]=='D') {	// 找到'D'了 
			return ud<=t;		// 访问u是否距离'S'小于t 
		} 
		for(int i=0; i<4; i++) {	// 尝试访问四个邻接结点 
			int newr = ur + dr[i];		// 邻居结点的坐标 
			int newc = uc + dc[i];
			int newd = ud + 1;			// 	邻居结点比u离S距离加1 
			if(0<=newr && newr<n && 0<=newc && newc<m	// 下标不能越界 
			&& G[newr][newc] != 'X'						// 不能是墙
			&& vis[newr][newc] == 0						// 没有访问过 
			) {
				vis[newr][newc] = 1;					// 进入队列前标记访问
				q.push(newd*100+newr*10+newc);			// 加入顶点编码的队尾 
			}
		} 
	}
	return false;	// 从'S'无法直接走到'D' 
} 

int main(){

	while(scanf("%d%d%d", &n, &m, &t)==3 && !(n==0&&m==0&&t==0)) {
		int sr, sc;		// 'S'的行号和列号 
		for(int i=0; i<n; i++) {
			scanf("%s", G[i]);	// 每次接收一行（没有空格） 
			for(int j=0; j<m; j++) {	// 找入口 
				if(G[i][j]=='S') {	
					sr = i, sc = j;
				}
			} 
		}
		printf("%s\n", bfs(sr, sc)?"YES":"NO");	// 从'S'开始广度优先搜索'D' 
	}

	return 0;
}

