#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
vector<int> tree[maxn];		// tree[i]����i���ĺ��� 
int sales[maxn];			// sales[i]��ʾi����������ֻ����Ҷ�ӽ�㣩
double rootPrice, precent;	// �����ۺ�ÿ�������۸���������	
double sum = 0;				// ��¼����Ҷ�ӽ���û��ļ۸��	 


void bfs() {
//	������ȱ���
	queue<int> q;	// ���У��������ڷ��ʵĽ��
	q.push(0);		// ��������
	int last = 0;	// ָ��ǰ���ʲ�����һ�����
	double price = rootPrice;	// ��ǰ��ļ۸� 
	while(!q.empty()) {
		int u = q.front();		// ���ʶ���Ԫ�� 
		q.pop();				// ��������Ԫ��
		if(tree[u].size()==0) sum += price*sales[u];	// �ۼ�Ҷ�ӽ��������	 
		for(int i=0; i<tree[u].size(); i++) {	// �������к��ӽ�� 
			q.push(tree[u][i]);
		}
		if(u==last) {	// �Ѿ����ʵ���ǰ�����һ����㣨����Ҫ�����ˣ�����ʱ��βԪ�ؾ�����һ�����һ����� 
			last = q.back();
			price = price*precent;		// ��һ��ļ۸� 
		} 
	} 
}


void dfs(int u, double price) {
// ������Ƚ��u�û���Ҫ�ļ۸�	
	if(tree[u].size()==0) sum += price * sales[u];		// �ۼ�Ҷ�ӽ��������
	else {
		for(int i=0; i<tree[u].size(); i++) {
			dfs(tree[u][i], price*precent);
		}
	} 
}
 
int main(){
	int n;			// ������� 
	
	scanf("%d%lf%lf", &n, &rootPrice, &precent);
	for(int i=0; i<n; i++) {
		int cnt, son;		// ���i�ĺ�������
		scanf("%d", &cnt);
		if(cnt>0) {
			for(int i=0; i<cnt; i++) {
				scanf("%d", &son);
				tree[i].push_back(son);
			} 	
		} else {	// Ҷ�ӽ�� 
			scanf("%d", &sales[i]); 
		}
	}
//	dfs(0, rootPrice);	
	bfs();
	printf("%.1lf\n", sum);
	return 0;
}

