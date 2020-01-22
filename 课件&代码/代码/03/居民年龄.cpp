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
	int age[101];	// age[i]保存年龄为i的居民数量
	while(scanf("%d", &n)==1 && n) {
		int x;
		memset(age, 0, sizeof(age));	// 初始化为0 
		for(int i=0; i<n; i++) {		// 统计n个居民的年龄 
			scanf("%d", &x);
			age[x]++;
		}
		for(int i=0; i<101; i++) {		// 从小到大输出age[i]个i(年龄) 
			for(int j=0; j<age[i]; j++) {
				printf("%d ", i);
			}
		}
		printf("\n");
	} 
	return 0;
}

