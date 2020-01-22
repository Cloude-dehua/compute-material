#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

bool isPrime(int x) {
// 判断x是否为素数
	int m = (int)(sqrt(x)+0.5); // 取平方根后四舍五入 
	for(int i=2; i<=m; i++) {	// 枚举[2, m]里所有可能被整除的数 
		if(x%i==0) return false;
	}	
	return true;
}

int isYeap(int y) {
	return y%4==0 && y%100!=0 || y%400==0;
}
int dayOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
	for(int y=1988; y<=1989; y++) {
		for(int m=1; m<=12; m++) {
			for(int d = 1; d<dayOfMonth[m] + (m==2 && isYeap(y)); d++) {
				int num = y*10000 + m*100 + d;
//				printf("==%d==\n", num);
				if(isPrime(num)) {
					printf("%d\n", num);
				}
			}
		}
	}

	return 0;
}

