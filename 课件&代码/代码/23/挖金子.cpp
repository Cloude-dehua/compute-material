/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
int max(int i, int j) {
	return i>j? i:j;
}
const int maxn = 200 + 10;
int a[maxn][maxn];	// a[i][j]����(i��j)�Ľ����� 
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
		for(int i=0; i<n; i++) {	// ���ÿһ���ܹ��ڵ���������������b������ 
			p[0] = a[i][0];		// ���Ƶĳ�ʼֵ 
			p[1] = a[i][1]; 
			p[2] = p[0] + a[i][2];	
			// pj��ʾѡ��xj��[x0,xj]�����ֵ 
			for(int j=3; j<m; j++) {	// ����[2,m���� 
				p[j] = a[i][j] + max(p[j-2], p[j-3]);
			}
			if(m==1) b[i] = p[0]; // ֻ��һ�� 
			else b[i] = max(p[m-2],p[m-1]);	// ��i�����ŷ��������ֵ 
//			printf("b[%d]=%d", i, b[i]); 
			
			if(i==0 || i==1) { // ѡ���0�л��1�� 
				c[i] = b[i];
			} else if (i==2) { 	// ѡ���˵�2��
				c[i] = b[0] + b[2];
			} else {
				c[i] = b[i] + max(c[i-2], c[i-3]); 	// c[i] ��ʾѡ����i��[b0, bi]���ֵ 
			}
		}
		int ans;
		if(n==1) ans = c[0]; // ֻ��һ�� 
		else ans = max(c[n-2],c[n-1]);	// �����ŷ��������ֵ 
		printf("%d\n", ans); 		
	}
	
	
	
	return 0;
}

