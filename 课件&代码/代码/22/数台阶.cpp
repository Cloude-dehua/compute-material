/**
µ«µ«øº—–Õ≈∂”
*/
#include <cstdio>
#include <cstring>
int fn[10];
/* 
*/ 

int f(int n){
	if(fn[n] >0) return fn[n];
	if(n<=0) return 0;
	if(n==1) return 1;
	if(n==2) return 2;
	fn[n-1] = f(n-1);
	fn[n-2] = f(n-2);
	return fn[n-1]+fn[n-2];
}

int main() {
	int n;
	while(scanf("%d", &n) == 1) {
		memset(fn, 0, sizeof(fn));
		fn[1] = 1;
		fn[2] = 2;
		for(int i=3; i<=10; i++) fn[i] = fn[i-1] + fn[i-2];
		printf("%d\n", fn[n]);
	}
	return 0;
}

