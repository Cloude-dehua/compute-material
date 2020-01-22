#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue> 
using namespace std;
typedef long long ll;
const int maxn = 2*100000+10;
int vis[maxn];		// vis[i]标记i结点是否被访问 
int d[maxn];		// d[i]保存i到N的最短距离（BFS搜索树的层次） 

int bfs(int n, int k) {
	queue<int> q;	// 保存正在访问的结点 
	q.push(n);		// 加入出发结点 
	memset(vis, 0, sizeof(vis));
	vis[n] = 1;
	d[n] = 0;
	while(!q.empty()) {	// 队列非空	
		int u = q.front();
		q.pop();
		
		if(u==k) {	// 找到了 
			return d[u];
		}
		// 将u没有访问过的邻接结点加入
		if(2*u<maxn && vis[2*u]==0) {
			vis[2*u] = 1;			// 处理邻接结点信息 
			d[2*u] = d[u]+1;
			q.push(2*u); 
		}
		if(1+u<maxn && vis[1+u]==0) {
			vis[1+u] = 1;			// 处理邻接结点信息 
			d[1+u] = d[u]+1;
			q.push(1+u); 
		}
		if(u-1>=0 && vis[u-1]==0) {
			vis[u-1] = 1;			// 处理邻接结点信息 
			d[u-1] = d[u]+1;
			q.push(u-1); 
		}
	}
	return -1;	// 没有找到 
}
int main(){
	int n, k;
	while(scanf("%d%d", &n, &k)==2) {
		printf("%d\n", bfs(n, k));
	}
	
	return 0;
}

