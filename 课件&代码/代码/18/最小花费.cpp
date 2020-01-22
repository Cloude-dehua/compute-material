#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 10;
double ac[maxn][maxn];				// 邻接矩阵 ac[i][j]保存i和j相互转账直接的通过率 
double pa[maxn];					// 保存A结点到其他结点的当前的最短距离 
int vis[maxn];						// vis[i]==1表示已经求得a->i最短路径 
int main(){
	int n, m;
	scanf("%d%d", &n, &m);		// 结点数量，边的数量
	int x, y, z;
	for(int i=0; i<m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		ac[x][y] = ac[y][x] = 1.0-z/100.0;		// 无向图, x和y转账的通过率 
	} 
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i=1; i<=n; i++) {	// 初始化pa 
		pa[i] = ac[a][i];	
	}
	vis[a] = 1;					// pa[i]==0表示已经求得到i结点的最短距离 
	for(int i=2; i<=n; i++) {	// 计算n-1个人到a最短距离 
		double max = 0;
		int ind;
		for(int j=1; j<=n; j++) {		// 在没有确定最短路径中的结点集合中选择一个最大的 
			if(vis[j]==0 && pa[j]>max) {	 
				max = pa[j];
				ind = j;
			}
		}
		vis[ind] = 1;		// 将j给加入 
		for(int j=1; j<=n; j++) {		// 更新通过率（最短路径） 
			if(vis[j]==0 && pa[ind]*ac[ind][j]>pa[j]) {	// pa[ind]：A->ind ac[ind][j]:ind->j  
				pa[j] = pa[ind]*ac[ind][j];
			}
		} 
	}
	printf("%.8lf", 100.0/pa[b]);		// a需要传给b的钱 

	return 0;
}

