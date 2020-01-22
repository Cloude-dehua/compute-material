/**
登登考研团队
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 16;
int a[maxn];	// 保存序列 
int primes[maxn*2];

// 判断x是否是素数 
int isPrime(int x) {
	for(int i=2; i<=x/2; i++) {
		if(x%i==0) return 0; 
	}
	return 1;
}
// 构造素数表 
void buildPrimes() {
	for(int i=2; i<maxn*2; i++) {
		primes[i] = isPrime(i);
	}
}
int main() {
	int n;
	buildPrimes();
	while(scanf("%d", &n) == 1) {
		for(int i=0; i<n; i++) a[i] = i+1;
		do{
			int ok = primes[ a[0]+a[n-1] ];	// 先检查首尾和 
			if(ok) {
				// 循环检查中间相邻的元素和是否为素数 
				for(int i=0; i<n-1; i++) {
					if(primes[ a[i]+a[i+1] ] == 0) {
						ok = 0;
						break;	
					}
				}
			}
			if(ok) {	// 满足条件打印 
				for(int i=0; i<n; i++) printf("%d ", a[i]);
				printf("\n");
			}
			
		} while(next_permutation(a+1, a+n));	// 枚举2~n的排列 
//		next_permutation(a+i, a+j) 对数组a[i,j)之间的数进行排列 
	}
	return 0;
}

