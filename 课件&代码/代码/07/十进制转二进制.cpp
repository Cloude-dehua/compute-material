#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
void jin(int n, int k, int* a, int& len) {
// 将十进制非负整数n转换为k进制保存在a中，转换后有len位
	if(n==0) {
		a[0] = 0;
		len = 1;
		return;
	}
	len = 0;
	while(n>0) {	// 大于0是模拟短除法 
		a[len++] = n%k;		// 拿到余数 
		n /= k;				// 拿到商 
	}	
}

int main(){
	int n;
	while(scanf("%d", &n)==1) {
//		int a[100], len;
//		jin(n, 2, a, len);
//		for(int i=len-1; i>=0; i--) {	// 从高到位输出每一位 
//			printf("%d", a[i]);
//		} 
	
		// 用逻辑与从高到第取出每位二进制数 
		int first = 1;	// 标记是否为前导零 
		for(int i=31; i>=0; i--) {
			if(n & 1<<i) {
				printf("1");
				first = 0;		// 标记后面的零为非前导零 
			} else {
				if(!first) 
					printf("0");
			}
		} 
	
		printf("\n");
	} 

	return 0;
}

