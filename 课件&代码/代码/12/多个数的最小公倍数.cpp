#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
// ��a��b�����Լ��
	return b==0?a:gcd(b, a%b);	
}

int main(){
	int n;
	while(scanf("%d",&n) ==1 && n) {
		int x, ans = 1;
		for(int i=0; i<n; i++) {	// ѭ����n��������С������ 
			scanf("%d", &x);
			ans = x/gcd(ans, x)*ans;
		}
		printf("%d\n", ans); 
	}

	return 0;
}

