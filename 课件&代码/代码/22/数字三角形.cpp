/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
// �Ż�i��j�нϴ��� 
int max(int i, int j) {
	return i>j ? i:j;
}
const int maxn = 10;
int p[maxn][maxn];
int f[maxn][maxn];	// f[i][j] ��ʾp[0][0]��p[i][j]·���ϵ�Ȩֵ�����Ϊf[i][j]
// f[i][j] = max(f[i-1][j], f[i-1][j-1]) + p[i][j]
int main() {
	int n;
	while(scanf("%d", &n) == 1) {
		// ���� 
		for(int i=0; i<n; i++) {
			for(int j=0; j<=i; j++) scanf("%d", &p[i][j]);
		}
		
//		f[0][0] = p[0][0];	// ��С������ 
//		for(int i=1; i<n; i++) {	// ����ԭ���� 
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

