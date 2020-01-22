/**
登登考研团队
*/
#include <cstdio>
// 状态定义m[i][j] 在j元以内考虑[1,i]物品能活动的最大价值
// m[i][j] = max(m[i-1][j], m[i-1][j-v[i]] + v[i]*w[j])
int m[26][30010];
int v[26];
int w[26];
int max(int a, int b) {
	return a>b?a:b;
}
int main() {
	int N, M;
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &N, &M);
		for(int i=1; i<=M; i++){
			scanf("%d%d", &v[i], &w[i]);	
		}  
		for(int i=1; i<=M; i++) {
			for(int j=1; j<=N; j++) {
				if(j-v[i]>=0) {	// 当前的钱可以买，考虑这个物品买和不买两种情况获得的最大价值 
					m[i][j] = max(m[i-1][j], m[i-1][j-v[i]] + v[i]*w[i]);
				} else {	// 卖不了 
					m[i][j] = m[i-1][j]; 
				} 
			}
		}
		printf("%d\n", m[M][N]);		
	}
	return 0;
}

