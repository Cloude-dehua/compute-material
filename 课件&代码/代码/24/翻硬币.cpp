/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
const int maxn = 20;
int a[maxn][maxn];
int b[maxn][maxn];	// �������з�ת������ 
char s[maxn];
int main() {
	int t;
	scanf("%d", &t);
	int kase = 1;
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%s", s);	// ���յ�i��
			for(int j=0; j<n; j++) {
				if(s[j]=='@') {	// ���� 
					a[i][j] = 0;
				} else {	// ���� 
					a[i][j] = 1;
				}
			} 
		}
		int mincnt = n*n+1;
		for(int i=0; i<(1<<n); i++) {	// ö�ٵ�һ�е�2^n����� 
			bool ok = true;	// Ĭ������ǿ��У�ֻ���ڷ��淭Ϊ�������� 
			int cnt =  0;	// ���� ���淭Ϊ�����Ӳ������ 
			for(int j=0; j<n; j++) {
				if(i & (1<<j)) {	// ȡ������i�ĵ�jλ��1��2���ƣ� 
					b[0][j] = 1;	// ���� 
					if(a[0][j]==0) cnt++;	// �ɷ��淴תΪ���� 
				} else {	// ��0 
					b[0][j] = 0;
					if(a[0][j]==1) {	// �����淴תΪ���� 
						ok = false;
						break;	
					}
				} 
			} 
			// ���ݵ����е�����������b����
			for(int i=1; ok && i<n; i++) {	// ���ʣ���[1, n)�� 
				for(int j=0; ok && j<n; j++) {	// ����i�е�n�� 
					b[i][j] = ((i-2>=0?b[i-2][j]:0) + (j-1>=0?b[i-1][j-1]:0) +(j+1<n?b[i-1][j+1]:0)) % 2;
					if(b[i][j]==0 && a[i][j]==1) {// �����淴תΪ���� 
						ok = false;
						break; 
					} else if(b[i][j]==1 && a[i][j]==0) { // �ɷ��淴תΪ���� 
						cnt++;
					}
				}
			} 
			if(ok && cnt<mincnt) {	// bȫ�������ɣ��÷������У�����Ǹ��Ž� 
				mincnt = cnt;
			} 
		}
		printf("Case %d: %d\n", kase++, (mincnt!=n*n+1)?mincnt:-1);
	}
	return 0;
}

