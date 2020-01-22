#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 10000;
vector<int> state[maxn];		// state[i]保存站台i的邻居站台 
int line[maxn][maxn];			// line[i][j]==k 表示站台i和站台j之间的铁轨是k号线 
int vis[maxn];					// vis[i]标记站台i是否访问 
vector<int> path;				// 保存搜索过程中的路径 
vector<int> ans;				// 最优路径 
int minStep = maxn;				// 记录所有搜索的路径中站台的最小数量
int minStrans = maxn;			// 记录所有搜索的路径中换乘的最小数量

int strans(vector<int> p) {
// 返回线路p的换乘数量
	int cnt = 0;	// 换乘数量
	int curLine = 0;	// 当前的线号 
	for(int i=0; i<p.size()-1; i++) {
		if(line[p[i]][p[i+1]]!=curLine) {	// p[i]和p[i+1]这条线路换了 
			cnt++;
			curLine = line[p[i]][p[i+1]];
		}
	}	
	return cnt;
}

void dfs(int u, int end) {
	vis[u] = 1;
	path.push_back(u);		// 将u站台添加到路径里 
	if(u==end) {	// 搜索到目标站台 
		if(path.size()<minStep || (path.size()==minStep && strans(path)<minStrans)) {	// 找到一条更优路径 
			ans = path;					// 更新最优路径信息 
			minStep = path.size();
			minStrans = strans(path); 
		} 
	}
	for(int i=0; i<state[u].size(); i++) {		// 访问u的邻居站台 
		if(vis[state[u][i]]==0) {
			dfs(state[u][i], end);
		}
	}
	// 回溯 
	vis[u] = 0; 		// 标记没有访问，因为其他线路也可能经过这个栈，我们需要找到所有线路 
	path.pop_back();	// 推出搜索线路 
}


int main(){
	int n;
	scanf("%d", &n);	// n条线 
	for(int i=1; i<=n; i++) {
		int m, pre, cur;
		scanf("%d%d", &m, &pre);	// 第i条线上有m个站
		for(int j=1; j<m; j++) {
			scanf("%d", &cur);
			state[pre].push_back(cur);	// 加入边（无向图） 
			state[cur].push_back(pre);
			line[pre][cur] = line[cur][pre] = i;	// 边的线路信息
			pre = cur; 		// 更新前一个站，方便和下一个栈对应 
		}
	} 
	int q;
	scanf("%d", &q);
	while(q--) {	// q次查询 
		int start, end;
		scanf("%d%d", &start, &end);
		memset(vis, 0, sizeof(vis));		// 初始化
		path.clear();
		minStep = maxn;
		minStrans = maxn;
		dfs(start, end);
		
		// 输出线路信息
		printf("%d\n", ans.size()-1);			// 起始站也在路径里，需要减去
		int curLine = line[ans[0]][ans[1]];	// 开始线号
		int pre = ans[0]; 					// 每条换乘线的起始站 
		for(int i=0; i<ans.size()-1; i++) {	
			if(curLine!=line[ans[i]][ans[i+1]]) {	// 换线了 
				printf("Take Line#%d from %d to %d.\n", curLine, pre, ans[i]);	// 打印线路信息 
				curLine = line[ans[i]][ans[i+1]];		// 更新线号 
				pre = ans[i];							// 更新起始端 
			}
		} 
		// 打印最后一条线
		printf("Take Line#%d from %d to %d.\n", curLine, pre, ans.back());	
	} 
	return 0;
}

