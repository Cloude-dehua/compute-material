#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 110; 
int a[maxn][maxn];	// a[i][j]==0��ʾ(i, j)û�б����ǣ�==1��ʾ������ 

int main(){
	int n, m, x1, y1, x2, y2;
	while(scanf("%d%d", &n, &m)==2) {
		memset(a, 0, sizeof(a));	// ��ʼ�������� 
		for(int i=0; i<m; i++) {	// ģ��m�Ź������ 
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for(int i=x1; i<x2; i++) {	// ��ǹ����򱻸��� 
				for(int j=y1; j<y2; j++) {
					a[i][j] = 1;
				}
			}
		}
		int ans = 0;
		// ������������л��ж���û�б����� 
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(a[i][j]==0) {
					ans++;
				}
			}
		}
		printf("%d\n", ans); 
	}

	return 0;
}

