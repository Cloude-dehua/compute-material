#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 35;
int a[maxn][maxn];		// 保存杨辉三角 
int main(){
	// 填充最大的杨辉三角 
	for(int i=1; i<maxn; i++) {		// 下标从1开始 
		for(int j=1; j<=i; j++) {
			if(j==1 || j==i) a[i][j] = 1;			// 第一列和对角线边界 
			else a[i][j] = a[i-1][j] + a[i-1][j-1];		// 正上方加左上方 
		}
	}
	
	int n;
	while(scanf("%d", &n)==1) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				if(j>1) printf(" ");
				printf("%d", a[i][j]);
			}
			printf("\n");	// 打印完当前行 
		} 
		printf("\n");		// 分割一组数据 
	}
	return 0;
}

