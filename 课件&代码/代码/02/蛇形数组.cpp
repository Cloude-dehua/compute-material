#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int m[10][10];		// 将结果填充到m数组 
int main(){
	int n;
	while(scanf("%d", &n)) {
		memset(m, 0, sizeof(0));
		int r=0, c=0, num=1;
		m[r][c] = num;	// 填第一个
		while(num<n*n) {	// 填充m未完成
			// 分别填充四个方向， 判断下一个位置是否可以填  
			while(c+1<n && m[r][c+1]==0) m[r][++c] = ++num;		// 右	
			while(r+1<n && m[r+1][c]==0) m[++r][c] = ++num;		// 下 
			while(c-1>=0 && m[r][c-1]==0) m[r][--c] = ++num;	// 左 
			while(r-1>=0 && m[r-1][c]==0) m[--r][c] = ++num;		// 上 
		}
		// 输出 
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				printf("%3d", m[i][j]);	
			}
			printf("\n");
		}
	}
	
	return 0;
}

