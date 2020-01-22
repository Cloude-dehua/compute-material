#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 25;
int G[maxn][maxn];		// ͼ���ڽӾ��� G[i][j]==1��ʾi��j������һ���� 
int vis[maxn];			// vis[i]��ǽ��i�Ƿ���� 
int n, m;
int cnt = 0;	// ��¼�������Ľ������ 
void dfs(int u) {
	vis[u] = 1;		// ���ʵ�ǰ����
	cnt++;
	for(int i=1; i<=n; i++) {			// ���Է�����Χû�з��ʹ����ھӽ�� 
		if(G[i][u]==1 && !vis[i]) {
			dfs(i);
		}
	} 
} 


int main(){

	while(scanf("%d%d", &n, &m)==2) {
		int a, b;		// ���ձߣ�a,b�� 
		memset(G, 0, sizeof(G));	// ��ʼ��G 
		for(int i=0; i<m; i++) {	// ����m���� 
			scanf("%d%d", &a, &b);
			G[a][b] = G[b][a] = 1;		// ����ͼ���ڽӾ����Ǹ��Գƾ��� 
		}
		if(m==n-1) {	// �������ıߵ��������ڶ���������һ 
			memset(vis, 0, sizeof(vis));		// ��ʼ��vis����
			cnt = 0;
			dfs(1);		// �Ӷ���1����ʼ����
			if(cnt==n) {	// ������n����㣬ͼ����ͨ��,�������� 
				printf("YES\n"); 
			} else {
				printf("NO\n");
			}
		} else {
			printf("NO\n");
		}
	} 

	return 0;
}

