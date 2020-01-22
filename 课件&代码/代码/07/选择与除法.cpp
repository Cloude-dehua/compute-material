#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

bool isPrime(int x) {
	int m = (int)(sqrt(x)+0.5);
	for(int i=2; i<=m; i++) {
		if(x%i==0) return false;
	}
	return true;
} 
const int maxn = 1e6;
int cnt = 0;
int primes[maxn];
int e[maxn];		// 
void build() {
	for(int i=2; i<maxn; i++) {
		if(isPrime[i]) {
			primes[cnt++] = i;
		}
	}
}

void pluss(int n, int d) {
// d=1表示乘以n,d=-1表示除以1, 将分解结果保存在e数组
	for(int i=0; i<cnt; i++) {	// 枚举所有素数 
		while(n%primes[i]==0) {	// 如果能整除当前素数 
			n /= primes[i];
			e[i] += d; 			// 乘除法对应指数加减 
		}
		if(n==1) break; 
	} 
}

void jie(int n, int d) {
// 将n!分解保存在e中
	for(int i=2; i<=n; i++) {
		pluss(i, d);
	}	
} 



int main(){
	int p, q, r, s;
	build();
	while(scanf("%d%d%d%d", &p, &q, &r, &s)==4) {
		memset(e, 0, sizeof(e));
		jie(p, 1);
		jie(q, -1);
		jie(p-q, -1);
		jie(r, -1);
		jie(s, 1);
		jie(r-s, 1);
	
		// 将质因子分解结果还原为double 
		double ans = 1.0;
		for(int i=0; i<cnt; i++) {
			if(e[i]>0) {
				while(e[i]--) ans *= primes[i];
			} else if(e[i]<0) {
				while(e[i]++) ans /= primes[i];
			} 
		}
		printf("%.5lf\n", ans);	
	}

	return 0;
}

