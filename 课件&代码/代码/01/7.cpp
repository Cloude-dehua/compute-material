#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll Jie(int n) {	// ��n�Ľ׳� 
	ll ans = 1;
	for(int i=1; i<=n; i++) {
		ans = i*ans;
	}
	return ans;
}

ll C(int m, int n) {	// �������,����д���ܻ��м������� 
	return Jie(n)/(Jie(m)*Jie(n-m));		// ��װ�׳˲��������ε��� 
} 

ll C2(int m, int n) {
	//C(m, n) == C(n-m, n)
	if(n-m<m) {		// ��һ���Ż� 
		m = n-m;
	}
	ll ans = 1, j=2;
	// n*(n-1)*...*(n-m+1)/(1*2*...*m)  
	for(int i=n; i>=n-m+1; i--) {	// ѭ������ 
		ans *= i;					// �������˷� 
		while(ans % j==0 && j<=m) {	// ������Գ�����ĸj�����ȳ����������Ի����м������� 
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

