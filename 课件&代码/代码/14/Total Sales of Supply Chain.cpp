#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
vector<int> tree[maxn];		// tree[i]保存i结点的孩子 
int sales[maxn];			// sales[i]表示i结点的销量（只保存叶子结点）
double rootPrice, precent;	// 出厂价和每层批发价格增长比率	
double sum = 0;				// 记录所有叶子结点拿货的价格和	 


void bfs() {
//	广度优先遍历
	queue<int> q;	// 队列，保存正在访问的结点
	q.push(0);		// 加入更结点
	int last = 0;	// 指向当前访问层的最后一个结点
	double price = rootPrice;	// 当前层的价格 
	while(!q.empty()) {
		int u = q.front();		// 访问队首元素 
		q.pop();				// 弹出队首元素
		if(tree[u].size()==0) sum += price*sales[u];	// 累加叶子结点进货金额	 
		for(int i=0; i<tree[u].size(); i++) {	// 加入所有孩子结点 
			q.push(tree[u][i]);
		}
		if(u==last) {	// 已经访问到当前层最后一个结点（马上要换层了），此时队尾元素就是下一层最后一个结点 
			last = q.back();
			price = price*precent;		// 下一层的价格 
		} 
	} 
}


void dfs(int u, double price) {
// 深度优先结点u拿货需要的价格	
	if(tree[u].size()==0) sum += price * sales[u];		// 累加叶子结点进货金额
	else {
		for(int i=0; i<tree[u].size(); i++) {
			dfs(tree[u][i], price*precent);
		}
	} 
}
 
int main(){
	int n;			// 结点数量 
	
	scanf("%d%lf%lf", &n, &rootPrice, &precent);
	for(int i=0; i<n; i++) {
		int cnt, son;		// 结点i的孩子数量
		scanf("%d", &cnt);
		if(cnt>0) {
			for(int i=0; i<cnt; i++) {
				scanf("%d", &son);
				tree[i].push_back(son);
			} 	
		} else {	// 叶子结点 
			scanf("%d", &sales[i]); 
		}
	}
//	dfs(0, rootPrice);	
	bfs();
	printf("%.1lf\n", sum);
	return 0;
}

