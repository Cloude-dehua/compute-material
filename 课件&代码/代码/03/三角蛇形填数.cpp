#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
int a[maxn][maxn];
int main(){
	int n;
	scanf("%d", &n);
	while(n--) {
		int m;
		scanf("%d", &m);
		memset(a, 0, sizeof(a));		// ��ʼ��a�������Ϊ0����ʾ��û����� 
		int r=0, c=0, num=1;
		a[r][c] = num;
		// ѭ����� 
		while(num<m*(m+1)/2) {	// num������m*(m-1)/2����ѭ�� 
			while(c+1<m && !a[r][c+1]) a[r][++c]=++num;// ��
			while(c-1>=0 && r+1<m && !a[r+1][c-1]) a[++r][--c]=++num;// ����
			while(r-1>=0 && !a[r-1][c]) a[--r][c]=++num;// �� 
		}
		// ���
		for(int i=0; i<m; i++) {
			for(int j=0; j<m-i; j++) {
				if(j>0) printf(" ");
				printf("%d", a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	} 

	return 0;
}

