#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
vector<int> a[maxn];		// 邻接表a[i]和i指向的顶点 
int indegree[maxn];			//  indegree[i]表示结点i的入度 
int topo[maxn];				// 保存拓扑排序的序列 
int main(){
	int n, m;	// n个顶点,m条边 
	while(scanf("%d%d", &n, &m)==2 && !(n==0 && m==0)) {
		// 初始化a和indegree数组 
		for(int i=1; i<=n; i++) a[i].clear();
		memset(indegree, 0, sizeof(indegree));	
		int x, y;
		for(int i=0; i<m; i++) {
			scanf("%d%d", &x, &y);	// 边<x,y>
			a[x].push_back(y); 
			indegree[y]++;
		} 
		stack<int> S;	// 保存入度为0的栈
		for(int i=1; i<=n; i++) {
			if(indegree[i]==0) {
				S.push(i); 
			}
		} 
		int cnt = 0;		// 删除的结点数量 
		while(!S.empty()) {	// 还有入度为0的顶点没有删 
			int u = S.top();// 访问栈顶元素
			S.pop();
			topo[cnt++] = u;// 将删除的顶点放入拓扑序列中
			for(int i=0; i<a[u].size(); i++) {	// 遍历u指向的顶点集 
				indegree[ a[u][i] ]--;			// 对于顶点的入度减一（删除了这条边） 
				if(indegree[ a[u][i] ] == 0) S.push(a[u][i]);	// 如果删完后入度为零加入栈 
			} 
		}
		if(cnt==n) {	// 删完了 
			for(int i=0; i<n; i++) {
				if(i>0) printf(" ");
				printf("%d", topo[i]);
			}
			printf("\n");
		} else {		// 没有删完，存在环 
			printf("-1\n");
		}
	}

	return 0;
}

