/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
#include <cstring> 
const int maxn = 110;
int a[maxn][maxn];	// �����ͼ 
int vis[maxn][maxn];	// vis[i][j]==0��ʾ����(i,j)û�з��� 
int dr[] = {-1, 1, 0, 0};	// �������飬���������ҵķ�������
int dc[] = {0, 0, -1, 1}; 
int n, m;
void dfs(int r, int c) {
	vis[r][c] = 1;	// ���ʣ�r,c������
	// ���Է�����Χû�з��ʹ���ˮ��
	for(int i=0; i<4; i++) {
		int newr = r + dr[i];	
		int newc = c + dc[i];
		if(0<=newr && newr<n && 0<=newc && newc<m 	// �±�û��Խ��
			&& a[newr][newc]==1	// �Ǹ�ˮ��
			&& vis[newr][newc]==0 // ˮ��û�з��� 
		) {
			dfs(newr, newc);	// dfs������Χ�����ˮ�� 
		} 
	} 
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++) {	// ���� 
			for(int j=0; j<m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		memset(vis, 0, sizeof(vis));	//��ʼ��vis���飬��ʾ���ж��㶼û�з��� 
		int cnt = 0;	// ˮ�أ���ͨ�飩������ 
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j]==1 && vis[i][j]==0) {	// ��ǰ������ˮ�ز���û�з��� 
					dfs(i,j);	// �ӵ�ǰ����������������ڵ���ͨ���е�����ˮ�� 
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

