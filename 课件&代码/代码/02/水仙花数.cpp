#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int t[10];		// 保存所有水仙花数 
	int cnt = 0;	// 记录水仙花数的个数 
	for(int a=1; a<10; a++) {			// 枚举百位 
		for(int b=0; b<10; b++) {		// 枚举十位
			for(int c=0; c<10; c++) {	// 枚举个位 
				int x = a*100 + b*10 + c;
				if(x== a*a*a+b*b*b+c*c*c) {	// 满足条件即是水仙花 
					t[cnt++] = x;		
				}
			}
		}
	} 
	
	int n, m;
	while(scanf("%d%d", &n, &m)==2) {		// ==2表示scanf成功接收两个数据 
		int flag = 0;
		for(int i=0; i<cnt; i++) {	// 遍历所有水仙花数 
			if(n<=t[i] && t[i]<=m) {
				if(flag) printf(" ");	// flag==0是只打印该数据，否则先打印一个空格，再输出数据，这样可以去掉行尾空格 
				flag = 1;
				printf("%d", t[i]);
			}
		}
		if(!flag) printf("no");		// flag==0表示[n,m]没有水仙花数 
		printf("\n");
	}
	

	return 0;
}

