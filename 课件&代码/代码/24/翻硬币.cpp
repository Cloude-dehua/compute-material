/**
登登考研团队
*/
#include <cstdio>
const int maxn = 20;
int a[maxn][maxn];
int b[maxn][maxn];	// 保存所有反转后的情况 
char s[maxn];
int main() {
	int t;
	scanf("%d", &t);
	int kase = 1;
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%s", s);	// 接收第i行
			for(int j=0; j<n; j++) {
				if(s[j]=='@') {	// 反面 
					a[i][j] = 0;
				} else {	// 正面 
					a[i][j] = 1;
				}
			} 
		}
		int mincnt = n*n+1;
		for(int i=0; i<(1<<n); i++) {	// 枚举第一行的2^n中情况 
			bool ok = true;	// 默认这个是可行：只存在反面翻为正面的情况 
			int cnt =  0;	// 计算 反面翻为正面的硬币数量 
			for(int j=0; j<n; j++) {
				if(i & (1<<j)) {	// 取得数字i的第j位是1（2进制） 
					b[0][j] = 1;	// 正面 
					if(a[0][j]==0) cnt++;	// 由反面反转为正面 
				} else {	// 是0 
					b[0][j] = 0;
					if(a[0][j]==1) {	// 由正面反转为反面 
						ok = false;
						break;	
					}
				} 
			} 
			// 根据第零行的情况填充整个b数组
			for(int i=1; ok && i<n; i++) {	// 填充剩余的[1, n)行 
				for(int j=0; ok && j<n; j++) {	// 填充第i行的n列 
					b[i][j] = ((i-2>=0?b[i-2][j]:0) + (j-1>=0?b[i-1][j-1]:0) +(j+1<n?b[i-1][j+1]:0)) % 2;
					if(b[i][j]==0 && a[i][j]==1) {// 由正面反转为反面 
						ok = false;
						break; 
					} else if(b[i][j]==1 && a[i][j]==0) { // 由反面反转为正面 
						cnt++;
					}
				}
			} 
			if(ok && cnt<mincnt) {	// b全部填充完成，该方案可行，如果是更优解 
				mincnt = cnt;
			} 
		}
		printf("Case %d: %d\n", kase++, (mincnt!=n*n+1)?mincnt:-1);
	}
	return 0;
}

