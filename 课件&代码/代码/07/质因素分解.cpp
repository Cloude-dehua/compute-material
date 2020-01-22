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

int main(){
	ll n;
	build();
	scanf("%lld", &n);
	int m = n;
	for(int i=0; i<cnt; i++) {	// ö���������� 
		while(n%primes[i]==0) {	// �����������ǰ���� 
			n /= primes[i];
			e[i]++; 			// ��Ӧָ����һ 
		}
		if(n==1) break; 
	}
	printf("%lld=", m);
	bool first = true;			// ����Ƿ��һ����� 
	for(int i=0; i<cnt; i++) {
		if(e[i]>0) {
			if(!first) printf("*");
			first = false;
			if(e[i]>1) {
				printf("%d^%d", primes[i], e[i]);
			} else {
				printf("%d", primes[i]);
			}
		}
	}
	printf("\n");
	return 0;
}

