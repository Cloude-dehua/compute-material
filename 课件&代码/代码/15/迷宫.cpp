#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 10;
char G[maxn][maxn];		// ��ͼ 
int vis[maxn][maxn];	// vis[i][j]==1��ʾ����(i, j)�Ѿ�������
int dr[] = {-1, 1, 0, 0};	// r����������:�������� 
int dc[] = {0, 0, -1, 1};
int n, m, t;
bool bfs(int r, int c) {
// �Ӷ���(r,c)��ʼ����
	memset(vis, 0, sizeof(vis));	// ��ʼ��vis����
	vis[r][c] = 1;	// ����(r,c)
	queue<int> q;		// �����������ʵĽ��ı���
	 // ����:drc r��ʮλ��c�ڸ�λ
	q.push(0*100+r*10+c);	// ����ʼ���'S'�ı���������
	while(!q.empty()) {
	 	int u = q.front();	// ���ʶ�ͷԪ��
		q.pop();			// ��������Ԫ��
		// ����
		int ur = u/10%10;	// ʮλ
		int uc = u%10;		// ��λ
		int ud = u/100;		// ��λ��������
		if(G[ur][uc]=='D') {	// �ҵ�'D'�� 
			return ud<=t;		// ����u�Ƿ����'S'С��t 
		} 
		for(int i=0; i<4; i++) {	// ���Է����ĸ��ڽӽ�� 
			int newr = ur + dr[i];		// �ھӽ������� 
			int newc = uc + dc[i];
			int newd = ud + 1;			// 	�ھӽ���u��S�����1 
			if(0<=newr && newr<n && 0<=newc && newc<m	// �±겻��Խ�� 
			&& G[newr][newc] != 'X'						// ������ǽ
			&& vis[newr][newc] == 0						// û�з��ʹ� 
			) {
				vis[newr][newc] = 1;					// �������ǰ��Ƿ���
				q.push(newd*100+newr*10+newc);			// ���붥�����Ķ�β 
			}
		} 
	}
	return false;	// ��'S'�޷�ֱ���ߵ�'D' 
} 

int main(){

	while(scanf("%d%d%d", &n, &m, &t)==3 && !(n==0&&m==0&&t==0)) {
		int sr, sc;		// 'S'���кź��к� 
		for(int i=0; i<n; i++) {
			scanf("%s", G[i]);	// ÿ�ν���һ�У�û�пո� 
			for(int j=0; j<m; j++) {	// ����� 
				if(G[i][j]=='S') {	
					sr = i, sc = j;
				}
			} 
		}
		printf("%s\n", bfs(sr, sc)?"YES":"NO");	// ��'S'��ʼ�����������'D' 
	}

	return 0;
}

