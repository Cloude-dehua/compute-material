#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>

typedef long long ll;
const int maxn = 100+10;
struct E {	// 边 
	int u, w;	//边的顶点
	int weight;	//边的权值  
} es[maxn];
int f[maxn];	// f[i]表示i结点的父节点 

bool cmp(E a, E b) {
	return a.weight < b.weight;
} 

int find(int a) {
	return a==f[a]?a:f[a] = find(f[a]);
}
int main(){
	int n;
	while(scanf("%d", &n)==1 && n) {	// n个顶点
		for(int i=0; i<n*(n-1)/2; i++) {	// 输入n*(n-1)/2条边 
			scanf("%d%d%d", &es[i].u, &es[i].w, &es[i].weight);
		} 
		for(int i=1; i<=n; i++) f[i]=i;	// 初始化每个顶点都是一个连通块 
		std::sort(es, es+n*(n-1)/2, cmp);	// 对所有边进行升序排序
		int ans = 0;
		for(int i=0, cnt=0; cnt<n && i<n*(n-1)/2; i++) {	// 从小到大考虑所有边，cnt是已经添加到生成树中的边数 
			int fu = find(es[i].u);		// 查找u和w所在在树的根（连通块） 
			int fw = find(es[i].w);
			if(fu!=fw) {	// 不在同一个连通块，才能添加这条边 
				f[fu] = fw;	// 合并树 
				ans += es[i].weight;		// 累加权值
				cnt++; 
			}
		} 
		printf("%d\n", ans); 
	}
	return 0;
}

