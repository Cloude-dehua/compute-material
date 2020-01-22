#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 15;
char map[maxn][maxn];
int vis[maxn][maxn];		// vis[i][j] ��ǽ��(i, j)�Ƿ���� 
int n, m;
void dfs(int r, int c) {
// ������ȱ�����㣨r,c�����ڵ���ͨ��	
	vis[r][c] = 1;		// ��Ƿ��� 
	for(int i=-1; i<=1; i++) {
		for(int j=-1; j<=1; j++) {
			if(0<=r+i&&r+i<n && 0<=c+j && c+j<m		// �±겻Խ�� 
			&& vis[r+i][c+j]==0						// û�з��� 
			&& map[r+i][c+j]=='@') {					// ��@�ַ�	
				dfs(r+i, c+j);
			} 
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%s", map[i]);
	}
	
	memset(vis, 0, sizeof(vis));		// ��ʼ��
	int ans = 0;						// ��¼��ͨ������ 
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!vis[i][j] && map[i][j]=='@') {	// ���(i,j)��һ��û�з��ʹ���@ 
				dfs(i, j);						// ������ʼ������ͨ�������е�@ 
				ans++;
			}
		}
	} 
	printf("%d\n", ans); 
	return 0;
}

