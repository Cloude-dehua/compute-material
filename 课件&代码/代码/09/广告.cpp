#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 110; 
int a[maxn][maxn];	// a[i][j]==0表示(i, j)没有被覆盖，==1表示覆盖了 

int main(){
	int n, m, x1, y1, x2, y2;
	while(scanf("%d%d", &n, &m)==2) {
		memset(a, 0, sizeof(a));	// 初始化公告栏 
		for(int i=0; i<m; i++) {	// 模拟m张广告张贴 
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for(int i=x1; i<x2; i++) {	// 标记广告局域被覆盖 
				for(int j=y1; j<y2; j++) {
					a[i][j] = 1;
				}
			}
		}
		int ans = 0;
		// 检查整改区域中还有多少没有被覆盖 
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(a[i][j]==0) {
					ans++;
				}
			}
		}
		printf("%d\n", ans); 
	}

	return 0;
}

