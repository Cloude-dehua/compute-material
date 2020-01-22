#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 200 + 10;
int a[maxn][maxn];	// a[i][j]保存第i行j列的金子 
int b[maxn];	// b[i]保存定第i行最多能挖的金子 
int d[maxn];	// d[i] = max(d[i-3],d[i-2]) + Xi， d[1] = X1, d[2] = X2 
int n, m; 
int main() {
	while(scanf("%d%d", &n, &m) == 2) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				scanf("%d", &a[i][j]); 
			}
		}
		for(int i=0; i<n; i++) {
			d[0] = a[i][0];
			d[1] = a[i][1];
			for(int j=2; j<m; j++) {
				if(j==2) d[j] = d[j-2] + a[i][j]; 	// 防止j-3下标越界 
				else d[j] = max(d[j-2], d[j-3]) + a[i][j];
			}
			if(m==1) b[i] = d[0];	// 注意m==1就只有一列,也是合法输入 
			else b[i] = max(d[m-1], d[m-2]);
		}
		d[0] = b[0];
		d[1] = b[1];
		for(int i=2; i<n; i++) {
			if(i==2) d[i] = d[i-2] + b[i];
			else d[i] = max(d[i-2], d[i-3]) + b[i];
		}
		int ans;
		if(n==1) ans = d[0]; // 注意n==1就只有一行,也是合法输入 
		else ans = max(d[n-1], d[n-2]);
		printf("%d\n", ans);
	}
	return 0;
}