#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 10;
double ac[maxn][maxn];				// �ڽӾ��� ac[i][j]����i��j�໥ת��ֱ�ӵ�ͨ���� 
double pa[maxn];					// ����A��㵽�������ĵ�ǰ����̾��� 
int vis[maxn];						// vis[i]==1��ʾ�Ѿ����a->i���·�� 
int main(){
	int n, m;
	scanf("%d%d", &n, &m);		// ����������ߵ�����
	int x, y, z;
	for(int i=0; i<m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		ac[x][y] = ac[y][x] = 1.0-z/100.0;		// ����ͼ, x��yת�˵�ͨ���� 
	} 
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i=1; i<=n; i++) {	// ��ʼ��pa 
		pa[i] = ac[a][i];	
	}
	vis[a] = 1;					// pa[i]==0��ʾ�Ѿ���õ�i������̾��� 
	for(int i=2; i<=n; i++) {	// ����n-1���˵�a��̾��� 
		double max = 0;
		int ind;
		for(int j=1; j<=n; j++) {		// ��û��ȷ�����·���еĽ�㼯����ѡ��һ������ 
			if(vis[j]==0 && pa[j]>max) {	 
				max = pa[j];
				ind = j;
			}
		}
		vis[ind] = 1;		// ��j������ 
		for(int j=1; j<=n; j++) {		// ����ͨ���ʣ����·���� 
			if(vis[j]==0 && pa[ind]*ac[ind][j]>pa[j]) {	// pa[ind]��A->ind ac[ind][j]:ind->j  
				pa[j] = pa[ind]*ac[ind][j];
			}
		} 
	}
	printf("%.8lf", 100.0/pa[b]);		// a��Ҫ����b��Ǯ 

	return 0;
}

