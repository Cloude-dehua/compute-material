/**
登登考研团队
*/
#include <cstdio>
int max(int i, int j) {
	return i>j? i:j;
}
const int maxn = 200 + 10;
int a[maxn][maxn];	// a[i][j]保存(i，j)的金子量 
int p[maxn];
int b[maxn];
int c[maxn];

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m)==2) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for(int i=0; i<n; i++) {	// 求的每一行能够挖得最大金子量保存在b数组中 
			p[0] = a[i][0];		// 递推的初始值 
			p[1] = a[i][1]; 
			p[2] = p[0] + a[i][2];	
			// pj表示选择xj后[x0,xj]的最大值 
			for(int j=3; j<m; j++) {	// 考虑[2,m）列 
				p[j] = a[i][j] + max(p[j-2], p[j-3]);
			}
			if(m==1) b[i] = p[0]; // 只有一列 
			else b[i] = max(p[m-2],p[m-1]);	// 第i行最优方案的最大值 
//			printf("b[%d]=%d", i, b[i]); 
			
			if(i==0 || i==1) { // 选择第0行或第1行 
				c[i] = b[i];
			} else if (i==2) { 	// 选择了第2行
				c[i] = b[0] + b[2];
			} else {
				c[i] = b[i] + max(c[i-2], c[i-3]); 	// c[i] 表示选择了i行[b0, bi]最大值 
			}
		}
		int ans;
		if(n==1) ans = c[0]; // 只有一行 
		else ans = max(c[n-2],c[n-1]);	// 总最优方案的最大值 
		printf("%d\n", ans); 		
	}
	
	
	
	return 0;
}

