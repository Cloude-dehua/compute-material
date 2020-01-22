#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10; 
int f[maxn];		// f[i]保存i结点的父结点,f[i]==i表示i是根结点 
int find(int x) {
// 找x所在树的根结点 
//	while(x!=f[x]) {	// x不是根结点 
//		x = f[x];		// x指向父结点 
//	}
//	return x;
	return x==f[x]?x:(f[x]=find(f[x]));		// 带路径压缩的查找，加查找路径上的结点全部直接挂载在根下 
}
 
int main(){
	int n, m;
	while(scanf("%d%d", &n, &m)==2 && n) {
		for(int i=1; i<=n; i++) f[i] = i;		// 每个顶点都是一个连通块（集合，树）
		int a, b;
		int cnt = n;	// 初试每个顶点都是一个连通块 
		while(m--) {	// 输入m条边 
			scanf("%d%d", &a, &b);
			int fa = find(a);
			int fb = find(b);
			if(fa != fb) {	// 根结点不一样，不在一棵树上 
				f[fa] = fb;	// 将fa这棵树挂载到fb下面 
				cnt--;			// 合并后连通块数量减一 
			}
		} 
		printf("%d\n", cnt-1);	// 需要增加边的数量 
	}

	return 0;
}

