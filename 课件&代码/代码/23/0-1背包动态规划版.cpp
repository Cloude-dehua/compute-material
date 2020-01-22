/**
登登考研团队
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m[22][2010];
int v[22], w[22]; 
int main() {
	// m[i][j] 表示在容量为j这种状态下考虑[0, i]背包能获得的最大价值
	// m[i][j] = max(m[i-1][j-wi] + vi , m[i-1][j])  
	// m[3][20]表示容量为20的情况下考虑[0,3]的一个组合能获得最大价值 
	int n, c;
	while(scanf("%d%d", &n, &c)==2) {
		memset(m, 0, sizeof(m));
		for(int i=1; i<=n; i++)  scanf("%d", &w[i]);	// 体积数组 
		for(int i=1; i<=n; i++)  scanf("%d", &v[i]);	// 价值数组
		for(int i=1; i<=c; i++) printf("%4d", i); 
		printf("\n");
		for(int i=1; i<=n; i++) {	// 考虑第i个物品是否拿入 
			for(int j=1; j<=c; j++) {	//表示在容量为j这种状态下考虑[0, i]背包能获得的最大价值
				if(j>=w[i])	// 在当前容量大于该物品的体积是，才考虑拿与不拿两种情况 
					m[i][j] = max(m[i-1][j-w[i]] + v[i] , m[i-1][j]);
				else 	// 否则第i个物品不拿 
					m[i][j] = m[i-1][j];
//				printf("第%d个物品容量为%d的获得最大价值") 
				printf("%4d", m[i][j]);
			}
			printf("\n");
		} 
		printf("%d\n", m[n][c]); 
		// 如何根据m数组还原最有方案 
	}	 
	
	return 0;
}

