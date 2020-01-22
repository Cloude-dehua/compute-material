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
bool primes[maxn];	// primes[i]==ture��ʾi������ 
void buildPrimes() {
// ����������
	int cnt = 0;	
	for(int i=0; i<maxn; i++) primes[i] = true;		// ��Ĭ�����ж���������Ȼ����ɸѡ 
	for(ll i=2; i<maxn; i++) {	 
		if(primes[i]) {		// �ж�i�Ƿ�Ϊ���� 
			for(ll j=i*i; j<maxn; j+=i) {	// ���i�ı�����������, i��С������� ������2*i��3*i,...i*i,(i+1)*i������(2i,3i,..., (i-1)*i)��ǰ���Ѿ���ɸѡ 
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
		int cnt = 0;	// ��ʾ��ǰ�жϵ��ǵڼ������� 
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

