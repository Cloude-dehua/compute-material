#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 3*1e6;
const int maxn2 = 1e5;
bool primes[maxn];	// primes[i]==ture表示i是素数 
void buildPrimes() {
// 构造素数表
	int cnt = 0;	
	for(int i=0; i<maxn; i++) primes[i] = true;		// 先默认所有都是素数，然后做筛选 
	for(ll i=2; i<maxn; i++) {	 
		if(primes[i]) {		// 判断i是否为素数 
			for(ll j=i*i; j<maxn; j+=i) {	// 标记i的倍数不是素数, i从小到大遍历 倍数：2*i，3*i,...i*i,(i+1)*i，但是(2i,3i,..., (i-1)*i)在前面已经别筛选 
				primes[j] = false;
			}
			cnt++;
			if(cnt>maxn2) break;
//			printf("%d--%d\n", cnt, i);	
		}
	}
//	printf("%d\n", cnt);
}

int main(){
//	freopen("a.txt", "w", stdout);
	buildPrimes();
	int n, m;
	while(scanf("%d%d", &n, &m)==2) {
		int cnt = 0;	// 表示当前判断的是第几个素数 
		for(int i=2; i<maxn; i++) {
			if(primes[i]) {
				cnt++;
				if(n<=cnt && cnt<=m) {
					printf("%d", i);
					if((cnt-n+1)%10==0 || cnt==m) printf("\n");
					else printf(" ");
				}
				if(cnt>m) break;
			}
		}
	}
	

	return 0;
}

