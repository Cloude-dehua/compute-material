#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 10000;
vector<int> state[maxn];		// state[i]����վ̨i���ھ�վ̨ 
int line[maxn][maxn];			// line[i][j]==k ��ʾվ̨i��վ̨j֮���������k���� 
int vis[maxn];					// vis[i]���վ̨i�Ƿ���� 
vector<int> path;				// �������������е�·�� 
vector<int> ans;				// ����·�� 
int minStep = maxn;				// ��¼����������·����վ̨����С����
int minStrans = maxn;			// ��¼����������·���л��˵���С����

int strans(vector<int> p) {
// ������·p�Ļ�������
	int cnt = 0;	// ��������
	int curLine = 0;	// ��ǰ���ߺ� 
	for(int i=0; i<p.size()-1; i++) {
		if(line[p[i]][p[i+1]]!=curLine) {	// p[i]��p[i+1]������·���� 
			cnt++;
			curLine = line[p[i]][p[i+1]];
		}
	}	
	return cnt;
}

void dfs(int u, int end) {
	vis[u] = 1;
	path.push_back(u);		// ��uվ̨��ӵ�·���� 
	if(u==end) {	// ������Ŀ��վ̨ 
		if(path.size()<minStep || (path.size()==minStep && strans(path)<minStrans)) {	// �ҵ�һ������·�� 
			ans = path;					// ��������·����Ϣ 
			minStep = path.size();
			minStrans = strans(path); 
		} 
	}
	for(int i=0; i<state[u].size(); i++) {		// ����u���ھ�վ̨ 
		if(vis[state[u][i]]==0) {
			dfs(state[u][i], end);
		}
	}
	// ���� 
	vis[u] = 0; 		// ���û�з��ʣ���Ϊ������·Ҳ���ܾ������ջ��������Ҫ�ҵ�������· 
	path.pop_back();	// �Ƴ�������· 
}


int main(){
	int n;
	scanf("%d", &n);	// n���� 
	for(int i=1; i<=n; i++) {
		int m, pre, cur;
		scanf("%d%d", &m, &pre);	// ��i��������m��վ
		for(int j=1; j<m; j++) {
			scanf("%d", &cur);
			state[pre].push_back(cur);	// ����ߣ�����ͼ�� 
			state[cur].push_back(pre);
			line[pre][cur] = line[cur][pre] = i;	// �ߵ���·��Ϣ
			pre = cur; 		// ����ǰһ��վ���������һ��ջ��Ӧ 
		}
	} 
	int q;
	scanf("%d", &q);
	while(q--) {	// q�β�ѯ 
		int start, end;
		scanf("%d%d", &start, &end);
		memset(vis, 0, sizeof(vis));		// ��ʼ��
		path.clear();
		minStep = maxn;
		minStrans = maxn;
		dfs(start, end);
		
		// �����·��Ϣ
		printf("%d\n", ans.size()-1);			// ��ʼվҲ��·�����Ҫ��ȥ
		int curLine = line[ans[0]][ans[1]];	// ��ʼ�ߺ�
		int pre = ans[0]; 					// ÿ�������ߵ���ʼվ 
		for(int i=0; i<ans.size()-1; i++) {	
			if(curLine!=line[ans[i]][ans[i+1]]) {	// ������ 
				printf("Take Line#%d from %d to %d.\n", curLine, pre, ans[i]);	// ��ӡ��·��Ϣ 
				curLine = line[ans[i]][ans[i+1]];		// �����ߺ� 
				pre = ans[i];							// ������ʼ�� 
			}
		} 
		// ��ӡ���һ����
		printf("Take Line#%d from %d to %d.\n", curLine, pre, ans.back());	
	} 
	return 0;
}

