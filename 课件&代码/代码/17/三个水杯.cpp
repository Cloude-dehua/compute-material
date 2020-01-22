#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
struct Node{		// 状态，即隐式图的结点 
	int a[3];		// a保存三个水杯中的水
	int d;			// 离初始状态的距离（BFS生成树的结点所在层次） 
};

int encoding(Node* n) {
// 将结点n编码为一个整数，表示他的状态码
	return n->a[0]*10000 + n->a[1]*100 + n->a[2];	
}

int bfs(Node* init, Node* end) {
// 从start结点开始广度优先搜索到end状态， init是水杯的初试容量,返回end里start最短距离 
	set<int> vis;		// vis来保存已经访问过的结点的状态码 
	queue<Node*> q;		// 队列，保存bfs过程中正在被访问的结点	
	Node* start = new Node();	
	start->a[0] = init->a[0];		// 第一个水杯是满的 
	start->a[1] = start->a[2] = 0;	// 第二、三水杯是空的 
	start->d = 0;					// 距离初试状态为0 
	vis.insert(encoding(start));	// 标记初试结点访问
	q.push(start);					// 加入到队尾
	
	while(!q.empty()) {	// 队列非空，表示有未访问完的结点
		Node* u = q.front();		// 访问队头元素 
		q.pop();		// 弹出队头元素 
//		printf("%d-%d-%d-%d\n", u->d, u->a[0], u->a[1], u->a[2]);
		if(encoding(u)==encoding(end)) {	// 如果相等就已经找到 
			return u->d;
		}
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {	
				if(i!=j) {			// 枚举所有i水杯到水进j水杯 
					Node* w = new Node();	// w是u的邻接矩阵 
					for(int k=0; k<3; k++) w->a[k] = u->a[k];	// 复制一份 
					if(w->a[i] <= (init->a[j] - w->a[j])) {	// i水杯里的水小于j剩余容量，可以全部倒入j 
						w->a[i] = 0;
//						w->a[j] = w->a[j] + w->a[i];
						w->a[j] = u->a[j] + u->a[i];	// 这里不能是w，因为上面已经修改了w->a[i]=0了 
					} else {	// 将j水杯倒满 
						w->a[i] = w->a[i] - (init->a[j] - w->a[j]);
						w->a[j] = init->a[j];
					}
					w->d = u->d + 1;		// w是从u搜索过来的，他的深度要加一 
//					if(w->a[0]+w->a[1]+w->a[2] != init->a[0]) {
//						printf("%d->%d\n", i, j);
//						printf("%d-%d-%d-%d\n", u->d, u->a[0], u->a[1], u->a[2]);
//						printf("%d-%d-%d-%d\n", w->d, w->a[0], w->a[1], w->a[2]);
//						break;
//					}
					if(vis.find(encoding(w)) == vis.end()) {	// w没有在vis集合里面 
						q.push(w);				// 加入队尾并标记访问 
						vis.insert(encoding(w));
					}
				}
			}
		} 
	} 
	return -1;	// 表示end没有找到 
}

int main(){
	int n;
	scanf("%d", &n);
	while(n--) {
		Node* init = new Node();
		Node* end = new Node();
		scanf("%d%d%d", &init->a[0], &init->a[1], &init->a[2]);
		scanf("%d%d%d", &end->a[0], &end->a[1], &end->a[2]);
		printf("%d\n", bfs(init, end));
	}
	
	

	return 0;
}

