/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
// ״̬����m[i][j] ��jԪ���ڿ���[1,i]��Ʒ�ܻ������ֵ
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
				if(j-v[i]>=0) {	// ��ǰ��Ǯ�����򣬿��������Ʒ��Ͳ������������õ�����ֵ 
					m[i][j] = max(m[i-1][j], m[i-1][j-v[i]] + v[i]*w[i]);
				} else {	// ������ 
					m[i][j] = m[i-1][j]; 
				} 
			}
		}
		printf("%d\n", m[M][N]);		
	}
	return 0;
}

