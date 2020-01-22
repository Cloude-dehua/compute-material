#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

bool isPrime(int x) {
// �ж�x�Ƿ�Ϊ���� 
	int m = (int)(sqrt(x)+0.5);
	for(int i=2; i<=m; i++) {		// �ж�[2, sqrt(x)]���Ƿ��������ܱ�x���� 
		if(x%i==0) return false;
	}
	return true;
}

const int maxn = 100;
int primes[maxn];
void build() {
// ���������primes 
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
//		for(int i=n; i>1; i--) {	// �Ӵ�С�ж�ÿһ���� 
//			if(n%i==0 && isPrime(i)) {	// ������ 
//				printf("%d\n", i);
//				break;
//			}
//		}

		// ˼·���������ӷֽ�
		int ans = 1;
		for(int i=0; i<maxn; i++) {
			while(n%primes[i]==0) {	// ����������ǰ���� 
				n /= primes[i];
				ans = primes[i];
			}
			if(n==1) break; 
		} 
		if(n!=1) ans = n;	// �п���nû�г�����n��һ���Ƚϴ�����������prime���У� 
		printf("%d\n", ans);
	}

	return 0;
}

