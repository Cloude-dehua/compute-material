/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 16;
int a[maxn];	// �������� 
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
int main() {
	int n;
	buildPrimes();
	while(scanf("%d", &n) == 1) {
		for(int i=0; i<n; i++) a[i] = i+1;
		do{
			int ok = primes[ a[0]+a[n-1] ];	// �ȼ����β�� 
			if(ok) {
				// ѭ������м����ڵ�Ԫ�غ��Ƿ�Ϊ���� 
				for(int i=0; i<n-1; i++) {
					if(primes[ a[i]+a[i+1] ] == 0) {
						ok = 0;
						break;	
					}
				}
			}
			if(ok) {	// ����������ӡ 
				for(int i=0; i<n; i++) printf("%d ", a[i]);
				printf("\n");
			}
			
		} while(next_permutation(a+1, a+n));	// ö��2~n������ 
//		next_permutation(a+i, a+j) ������a[i,j)֮������������� 
	}
	return 0;
}

