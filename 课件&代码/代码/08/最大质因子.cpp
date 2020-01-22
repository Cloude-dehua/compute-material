#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

bool isPrime(int x) {
// 判断x是否为素数 
	int m = (int)(sqrt(x)+0.5);
	for(int i=2; i<=m; i++) {		// 判断[2, sqrt(x)]中是否有数字能被x整除 
		if(x%i==0) return false;
	}
	return true;
}

const int maxn = 100;
int primes[maxn];
void build() {
// 填充素数表primes 
	int cnt = 0;
	for(int i=2; cnt<maxn; i++) {
		if(isPrime(i)) {
			primes[cnt++] = i;
		}
	}
}

int main(){
	int n;
	build();
	while(scanf("%d", &n)==1) {
//		for(int i=n; i>1; i--) {	// 从大到小判断每一个数 
//			if(n%i==0 && isPrime(i)) {	// 质因子 
//				printf("%d\n", i);
//				break;
//			}
//		}

		// 思路二：质因子分解
		int ans = 1;
		for(int i=0; i<maxn; i++) {
			while(n%primes[i]==0) {	// 可以整除当前素数 
				n /= primes[i];
				ans = primes[i];
			}
			if(n==1) break; 
		} 
		if(n!=1) ans = n;	// 有可能n没有除尽（n是一个比较大素数，不在prime表中） 
		printf("%d\n", ans);
	}

	return 0;
}

