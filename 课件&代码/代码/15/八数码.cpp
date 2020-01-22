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
// 隐式图搜索问题：路径是否可达，最短路径
// 状态对于图中的一个顶点，状态直接转换就是图的一条边 
struct Node{	// 每个八数码中的状态，对应图中的顶点 
	int a[9];		// 八数码的布局信息
	int d;			// d表示离初始化顶点的距离 
};
int dr[] = {-1, 1, 0, 0};	// r的搜索方向:上下左右 
int dc[] = {0, 0, -1, 1};


void print(Node* u) {
	printf("%d\n", u->d);
	for(int i=0; i<9; i++) {
		printf("%3d", u->a[i]);
		if((i+1)%3==0) printf("\n");
	}
}

int encoding(Node* u) {
// 将状态u中a的9个数字直接拼接成一个数字 
	int code = 0;
	for(int i=0; i<9; i++) {
		code = code*10+u->a[i];
	}
	return code; 
} 
int bfs(Node* start, Node* end) {
	queue<Node*> q;		// 保存正在访问的顶点
	q.push(start);
	set<int> vis;				// 将访问过的结点编码保存在set集合里面
	vis.insert(encoding(start));		// 标记start访问 
	while(!q.empty()) {
		Node* u = q.front();
		q.pop();
//		print(u);
		// 检查u是否是end
		int ok = 1;
		for(int i=0; i<9; i++) {
			if(u->a[i]!=end->a[i]) {
				ok = 0;
				break;
			}
		}
		if(ok) {	// 找到end了 
			return u->d;
		}
		int z, zr, zc;	// 0的序列位置和行号了列号
		for(int i=0; i<9; i++) {
			if(u->a[i]==0) {
				z = i;
				zr = i / 3;
				zc = i % 3;
				break;
			}
		} 
		for(int i=0; i<4; i++) {	// 尝试0的四个方向搜索 
			int newr = zr+dr[i];	// 邻居结点0的位置 
			int newc = zc+dc[i];
			int newz = newr*3+newc;
//			printf("newr=%d, zr=%d, newc=%d, zc=%d\n", newr, zr, newc, zc);
			if(0<=newr && newr<3 && 0<=newc && newc<3) {
				Node* w = new Node();
				for(int j=0; j<9; j++) w->a[j] = u->a[j];	// 复制原来的u的状态（因为只是0和其旁边的数字交换了，大部分没有动）	
				w->a[newz] = u->a[z];		// 交换0和其旁边的一个数字 
				w->a[z] = u->a[newz];
				w->d = u->d + 1;			// 层次加一 
//				print(w); 
				if(vis.find(encoding(w))==vis.end()) {	// w不在vis中，即没有访问过 
					vis.insert(encoding(w));	// 在添加队尾前比较访问 
					q.push(w);					// 添加队尾
				} 
			}
		}
	}
	return -1;		// 没有找到end 
}

int main(){
	Node* start = new Node();		// 初始状态
	Node* end = new Node();			// 目标状态
	for(int i=0; i<9; i++) scanf("%d", &start->a[i]); 
	for(int i=0; i<9; i++) scanf("%d", &end->a[i]);
	start->d = 0;
	printf("%d\n", bfs(start, end));
	return 0;
}

