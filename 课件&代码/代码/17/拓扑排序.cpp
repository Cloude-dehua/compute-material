#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
vector<int> a[maxn];		// �ڽӱ�a[i]��iָ��Ķ��� 
int indegree[maxn];			//  indegree[i]��ʾ���i����� 
int topo[maxn];				// ����������������� 
int main(){
	int n, m;	// n������,m���� 
	while(scanf("%d%d", &n, &m)==2 && !(n==0 && m==0)) {
		// ��ʼ��a��indegree���� 
		for(int i=1; i<=n; i++) a[i].clear();
		memset(indegree, 0, sizeof(indegree));	
		int x, y;
		for(int i=0; i<m; i++) {
			scanf("%d%d", &x, &y);	// ��<x,y>
			a[x].push_back(y); 
			indegree[y]++;
		} 
		stack<int> S;	// �������Ϊ0��ջ
		for(int i=1; i<=n; i++) {
			if(indegree[i]==0) {
				S.push(i); 
			}
		} 
		int cnt = 0;		// ɾ���Ľ������ 
		while(!S.empty()) {	// �������Ϊ0�Ķ���û��ɾ 
			int u = S.top();// ����ջ��Ԫ��
			S.pop();
			topo[cnt++] = u;// ��ɾ���Ķ����������������
			for(int i=0; i<a[u].size(); i++) {	// ����uָ��Ķ��㼯 
				indegree[ a[u][i] ]--;			// ���ڶ������ȼ�һ��ɾ���������ߣ� 
				if(indegree[ a[u][i] ] == 0) S.push(a[u][i]);	// ���ɾ������Ϊ�����ջ 
			} 
		}
		if(cnt==n) {	// ɾ���� 
			for(int i=0; i<n; i++) {
				if(i>0) printf(" ");
				printf("%d", topo[i]);
			}
			printf("\n");
		} else {		// û��ɾ�꣬���ڻ� 
			printf("-1\n");
		}
	}

	return 0;
}

