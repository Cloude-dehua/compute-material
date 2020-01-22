#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 10000 + 10;
int f[maxn];		// f[i]表示i结点的父节点，f[i]==i为根结点 
int find(int a) {
// 查找a结点所在树的根
	return a==f[a] ? a : f[a] = find(f[a]);		// 带路径压缩查找，将查找路径上的结点都直接挂载在根结点下面 
}
int main(){

	int n, m;
	while(scanf("%d%d", &n, &m)==2 && !(n==0 && m==0)) {	// n个人(图中的结点), m个同名族关系（图中的边）
		for(int i=1; i<=n; i++) f[i] = i;	// 每个结点都是一个连通块（集合、树）
		int a, b;
		int ans = n;		// 初试是有n个连通块 
		while(m--) {		// 添加m条边 
			scanf("%d%d", &a, &b);	// 添加（a,b）边 
			int fa = find(a);
			int fb = find(b);
			if(fa != fb) {
				f[fa] = fb;	// 将fa挂载到fb下面 
				ans--;
			}
		} 
		printf("%d\n", ans); 
	}
	return 0;
}

