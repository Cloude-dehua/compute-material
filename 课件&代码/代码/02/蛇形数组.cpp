#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int m[10][10];		// �������䵽m���� 
int main(){
	int n;
	while(scanf("%d", &n)) {
		memset(m, 0, sizeof(0));
		int r=0, c=0, num=1;
		m[r][c] = num;	// ���һ��
		while(num<n*n) {	// ���mδ���
			// �ֱ�����ĸ����� �ж���һ��λ���Ƿ������  
			while(c+1<n && m[r][c+1]==0) m[r][++c] = ++num;		// ��	
			while(r+1<n && m[r+1][c]==0) m[++r][c] = ++num;		// �� 
			while(c-1>=0 && m[r][c-1]==0) m[r][--c] = ++num;	// �� 
			while(r-1>=0 && m[r-1][c]==0) m[--r][c] = ++num;		// �� 
		}
		// ��� 
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				printf("%3d", m[i][j]);	
			}
			printf("\n");
		}
	}
	
	return 0;
}

