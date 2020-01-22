#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int n;
	while(scanf("%d", &n)==1) {
		int m=0;
		int tmp = n;
		while(tmp>0) {
			m = m*10 + tmp%10;		// 往前进位加上个位 
			tmp /= 10;				// 擦除个位 
		}
		if(m%n==0) {	// 可以整除 
			printf("%d*%d=%d\n", n, m/n, m);
		} else {
			printf("%d ", n);
			// 打印m的前导0
			tmp = n;
			while(tmp>10 && tmp%10==0) {	// 判断n的低位有几个零 
				printf("0");
				tmp /= 10;	
			} 
			printf("%d\n", m);
		}
		
	}

	return 0;
}

