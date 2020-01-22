/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
#include <cstring>

const int maxn = 20;
int a[maxn];	// �������� 
int vis[maxn];
int n;
int primes[maxn*2];
// �ж�x�Ƿ������� 
int isPrime(int x) {
	for(int i=2; i<=x/2; i++) {
		if(x%i==0) return 0; 
	}
	return 1;
}
// ���������� 
void buildPrimes() {
	for(int i=2; i<maxn*2; i++) {
		primes[i] = isPrime(i);
	}
}
// 1 4 
void dfs(int cur) {
	if(cur==n && primes[a[0]+a[n-1]]) {	// ����Ҷ�ӽڵ� 
		for(int i=0; i<n; i++) {
//			if(i!=0) printf(" "); 
			printf("%d ", a[i]);	
		}
		printf("\n");
	} else {
		for(int i=2; i<=n; i++) {	// ���� ��2~n����a[cur] 
			if(vis[i]==0 && primes[i+a[cur-1]]) {	// ��ǰiû��ʹ�� ����鵱ǰi���������ǰ�����֮�ͷ���������ͻ 
				a[cur] = i;
				vis[i] = 1;
				dfs(cur + 1);
				vis[i] = 0;	// ���� 
			}
		}
	}
} 
int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("a.txt", "w", stdout);
	buildPrimes();
	while(scanf("%d", &n) == 1) {
		a[0] = 1;
		memset(vis, 0, sizeof(vis));
		dfs(1);
	}	
	return 0;
}

