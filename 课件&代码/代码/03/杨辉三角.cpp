#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 35;
int a[maxn][maxn];		// ����������� 
int main(){
	// �������������� 
	for(int i=1; i<maxn; i++) {		// �±��1��ʼ 
		for(int j=1; j<=i; j++) {
			if(j==1 || j==i) a[i][j] = 1;			// ��һ�кͶԽ��߽߱� 
			else a[i][j] = a[i-1][j] + a[i-1][j-1];		// ���Ϸ������Ϸ� 
		}
	}
	
	int n;
	while(scanf("%d", &n)==1) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				if(j>1) printf(" ");
				printf("%d", a[i][j]);
			}
			printf("\n");	// ��ӡ�굱ǰ�� 
		} 
		printf("\n");		// �ָ�һ������ 
	}
	return 0;
}

