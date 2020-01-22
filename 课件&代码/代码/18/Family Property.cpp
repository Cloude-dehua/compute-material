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
const int maxn = 10000;
vector<int> a[maxn]; 	// a[i]����i���ھӽ�� 
int esNum[maxn];		// esNum[i]����i���ķ�������
double esArea[maxn];	// esNum[i]����i���ķ������ 
int vis[maxn];			// vis[i]���i����Ƿ���� 
struct Family{
	int id;		// ��ͥid 
	int num;	// ��ͥ��Ա����
	double avgEsNum;	// ƽ����������
	double avgEsArea;	// ƽ��������� 
	Family(int id) {
		this->id = id;
		num = 0;
		avgEsNum = 0;
		avgEsArea = 0;
	}
};
vector<Family> ans;
void bfs(int id) {
// �ӵ�ǰid�������������ڵ���ͨ����Ϣ
	Family f(id);
	queue<int> q;
	q.push(id);
	vis[id] = 1;
	while(!q.empty()) {
		int u = q.front();	// ���ʶ��� 
		q.pop();			// �������� 
		
		// ͳ��family��Ϣ
		if(u < f.id) f.id = u; 
		f.num++;
		f.avgEsNum += esNum[u];
		f.avgEsArea += esArea[u];
		
		for(int i=0; i<a[u].size(); i++) {	// ����û�б��������ھӽ�� 
			if(vis[a[u][i]] == 0) {			 
				vis[a[u][i]] = 1;
				q.push(a[u][i]);
			} 
		}
	}
	f.avgEsArea /= f.num;
	f.avgEsNum /= f.num;
	
	ans.push_back(f);	
}
bool cmp(Family a, Family b) {		// ��ͥ������� 
	if(a.avgEsArea != b.avgEsArea) return a.avgEsArea > b.avgEsArea;
	else return a.id < b.id;
}
int main(){
	int n;
	scanf("%d", &n);
	vector<int> ids;	// �����˵�id 
	int id, fa, ma, sonnum, son;
	for(int i=0; i<n; i++) {
		scanf("%d%d%d", &id, &fa, &ma);
		ids.push_back(id);
		if(fa!=-1) {	// ���ڸ��� 
			a[id].push_back(fa);	// ����ͼ����ӱ�(id, fa)
			a[fa].push_back(id);
		}
		if(ma!=-1) {
			a[id].push_back(ma);
			a[ma].push_back(id);
		}
		scanf("%d", &sonnum);
		for(int i=0; i<sonnum; i++) {
			scanf("%d", &son);
			a[id].push_back(son);
			a[son].push_back(id); 
		}
		scanf("%d%lf", &esNum[id], &esArea[id]);
	}
	for(int i=0; i<ids.size(); i++) {	// ���Է�������id 
		if(vis[ids[i]]==0) {
			bfs(ids[i]);
		}
	} 
	sort(ans.begin(), ans.end(), cmp);	// ���� 
	printf("%d\n", ans.size());			// ��ͥ���� 
	for(int i=0; i<ans.size(); i++) {	// ÿ����ͥ����Ϣ 
		printf("%04d %d %.3lf %.3lf\n", ans[i].id, ans[i].num, ans[i].avgEsNum, ans[i].avgEsArea);
	}
	return 0;
}

