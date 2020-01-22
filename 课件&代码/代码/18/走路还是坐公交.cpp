#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue> 
using namespace std;
typedef long long ll;
const int maxn = 2*100000+10;
int vis[maxn];		// vis[i]���i����Ƿ񱻷��� 
int d[maxn];		// d[i]����i��N����̾��루BFS�������Ĳ�Σ� 

int bfs(int n, int k) {
	queue<int> q;	// �������ڷ��ʵĽ�� 
	q.push(n);		// ���������� 
	memset(vis, 0, sizeof(vis));
	vis[n] = 1;
	d[n] = 0;
	while(!q.empty()) {	// ���зǿ�	
		int u = q.front();
		q.pop();
		
		if(u==k) {	// �ҵ��� 
			return d[u];
		}
		// ��uû�з��ʹ����ڽӽ�����
		if(2*u<maxn && vis[2*u]==0) {
			vis[2*u] = 1;			// �����ڽӽ����Ϣ 
			d[2*u] = d[u]+1;
			q.push(2*u); 
		}
		if(1+u<maxn && vis[1+u]==0) {
			vis[1+u] = 1;			// �����ڽӽ����Ϣ 
			d[1+u] = d[u]+1;
			q.push(1+u); 
		}
		if(u-1>=0 && vis[u-1]==0) {
			vis[u-1] = 1;			// �����ڽӽ����Ϣ 
			d[u-1] = d[u]+1;
			q.push(u-1); 
		}
	}
	return -1;	// û���ҵ� 
}
int main(){
	int n, k;
	while(scanf("%d%d", &n, &k)==2) {
		printf("%d\n", bfs(n, k));
	}
	
	return 0;
}

