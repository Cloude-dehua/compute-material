#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int a, b;	// 定义变量 
	while(scanf("%d%d", &a, &b)==2) {		// 利用scanf的返回值来处理多组数据 
		printf("%d\n", a+b);	
	}
	return 0;
}

