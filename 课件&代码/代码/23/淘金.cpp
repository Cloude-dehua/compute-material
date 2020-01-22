#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 200 + 10;
int a[maxn][maxn];	// a[i][j]�����i��j�еĽ��� 
int b[maxn];	// b[i]���涨��i��������ڵĽ��� 
int d[maxn];	// d[i] = max(d[i-3],d[i-2]) + Xi�� d[1] = X1, d[2] = X2 
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
				if(j==2) d[j] = d[j-2] + a[i][j]; 	// ��ֹj-3�±�Խ�� 
				else d[j] = max(d[j-2], d[j-3]) + a[i][j];
			}
			if(m==1) b[i] = d[0];	// ע��m==1��ֻ��һ��,Ҳ�ǺϷ����� 
			else b[i] = max(d[m-1], d[m-2]);
		}
		d[0] = b[0];
		d[1] = b[1];
		for(int i=2; i<n; i++) {
			if(i==2) d[i] = d[i-2] + b[i];
			else d[i] = max(d[i-2], d[i-3]) + b[i];
		}
		int ans;
		if(n==1) ans = d[0]; // ע��n==1��ֻ��һ��,Ҳ�ǺϷ����� 
		else ans = max(d[n-1], d[n-2]);
		printf("%d\n", ans);
	}
	return 0;
}