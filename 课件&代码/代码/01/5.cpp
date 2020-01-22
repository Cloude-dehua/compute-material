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
	scanf("%d", &n);
	for(int i=1; i<=n ; i++) {		// 用for循环来处理 
		if(i>1) printf(",");		// 处理行末分割符的常用手段 
		printf("%d", i);
	}
	return 0;
}

