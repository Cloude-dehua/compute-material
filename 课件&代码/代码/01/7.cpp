#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll Jie(int n) {	// 算n的阶乘 
	ll ans = 1;
	for(int i=1; i<=n; i++) {
		ans = i*ans;
	}
	return ans;
}

ll C(int m, int n) {	// 算组合数,这样写可能会中间过程溢出 
	return Jie(n)/(Jie(m)*Jie(n-m));		// 封装阶乘操作方便多次调用 
} 

ll C2(int m, int n) {
	//C(m, n) == C(n-m, n)
	if(n-m<m) {		// 进一步优化 
		m = n-m;
	}
	ll ans = 1, j=2;
	// n*(n-1)*...*(n-m+1)/(1*2*...*m)  
	for(int i=n; i>=n-m+1; i--) {	// 循环分子 
		ans *= i;					// 分子做乘法 
		while(ans % j==0 && j<=m) {	// 如果可以除尽分母j，则先除，这样可以缓解中间过程溢出 
			ans /=j;
			j++;
		}
	}
	return ans;
}

int main(){
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%lld\n", C2(m, n));

	return 0;
}

