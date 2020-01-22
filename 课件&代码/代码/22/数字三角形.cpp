/**
登登考研团队
*/
#include <cstdio>
// 放回i和j中较大者 
int max(int i, int j) {
	return i>j ? i:j;
}
const int maxn = 10;
int p[maxn][maxn];
int f[maxn][maxn];	// f[i][j] 表示p[0][0]到p[i][j]路径上的权值和最大为f[i][j]
// f[i][j] = max(f[i-1][j], f[i-1][j-1]) + p[i][j]
int main() {
	int n;
	while(scanf("%d", &n) == 1) {
		// 输入 
		for(int i=0; i<n; i++) {
			for(int j=0; j<=i; j++) scanf("%d", &p[i][j]);
		}
		
//		f[0][0] = p[0][0];	// 最小子问题 
//		for(int i=1; i<n; i++) {	// 构造原问题 
//			for(int j=0; j<=i; j++) {
//				if(j==0) f[i][j] = f[i-1][j] + p[i][j];
//				else f[i][j] = max(f[i-1][j], f[i-1][j-1]) + p[i][j];
//			}
//		}
//		int ans = f[n-1][0];
//		for(int i=0; i<n; i++) {
//			ans = max(ans, f[n-1][i]);
//		}
		
		for(int i=0; i<n; i++) f[n-1][i] = p[n-1][i];
		for(int i=n-2; i>=0; i--) {
			for(int j=0; j<=i; j++) {
				f[i][j] = max(f[i+1][j+1], f[i+1][j]) + p[i][j];
			}
		}
		printf("%d\n", f[0][0]);
	}
	return 0;
}

