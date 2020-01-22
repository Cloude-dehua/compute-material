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
vector<int> a[maxn]; 	// a[i]保存i的邻居结点 
int esNum[maxn];		// esNum[i]保存i结点的房子数量
double esArea[maxn];	// esNum[i]保存i结点的房子面积 
int vis[maxn];			// vis[i]标记i结点是否访问 
struct Family{
	int id;		// 家庭id 
	int num;	// 家庭人员数量
	double avgEsNum;	// 平均房子数量
	double avgEsArea;	// 平均房子面积 
	Family(int id) {
		this->id = id;
		num = 0;
		avgEsNum = 0;
		avgEsArea = 0;
	}
};
vector<Family> ans;
void bfs(int id) {
// 从当前id结点出发搜索所在的连通块信息
	Family f(id);
	queue<int> q;
	q.push(id);
	vis[id] = 1;
	while(!q.empty()) {
		int u = q.front();	// 访问队首 
		q.pop();			// 弹出队首 
		
		// 统计family信息
		if(u < f.id) f.id = u; 
		f.num++;
		f.avgEsNum += esNum[u];
		f.avgEsArea += esArea[u];
		
		for(int i=0; i<a[u].size(); i++) {	// 访问没有遍历过的邻居结点 
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
bool cmp(Family a, Family b) {		// 家庭排序规则 
	if(a.avgEsArea != b.avgEsArea) return a.avgEsArea > b.avgEsArea;
	else return a.id < b.id;
}
int main(){
	int n;
	scanf("%d", &n);
	vector<int> ids;	// 若有人的id 
	int id, fa, ma, sonnum, son;
	for(int i=0; i<n; i++) {
		scanf("%d%d%d", &id, &fa, &ma);
		ids.push_back(id);
		if(fa!=-1) {	// 存在父亲 
			a[id].push_back(fa);	// 无向图中添加边(id, fa)
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
	for(int i=0; i<ids.size(); i++) {	// 尝试访问所有id 
		if(vis[ids[i]]==0) {
			bfs(ids[i]);
		}
	} 
	sort(ans.begin(), ans.end(), cmp);	// 排序 
	printf("%d\n", ans.size());			// 家庭数量 
	for(int i=0; i<ans.size(); i++) {	// 每个家庭的信息 
		printf("%04d %d %.3lf %.3lf\n", ans[i].id, ans[i].num, ans[i].avgEsNum, ans[i].avgEsArea);
	}
	return 0;
}

