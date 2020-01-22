#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[3][3];
int b[3][3];	// 转置后的矩阵 
void T(int n, int m) {
// 加n行m列的数组转置完后放入b 
	for(int i=0; i<n; i++) {		// 遍历二维数组 
		for(int j=0; j<m; j++) {
			b[j][i] = a[i][j];		// 将行号和列号交换后复制 
		}
	} 
} 

int main(){
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
//	
//	for(int j=0; j<3; j++) {
//		for(int i=0; i<3; i++) {
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	

	T(3, 3);	// 转置操作
	
	// 输出 
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}


	return 0;
}

