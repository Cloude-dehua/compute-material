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
struct Node{		// ״̬������ʽͼ�Ľ�� 
	int a[3];		// a��������ˮ���е�ˮ
	int d;			// ���ʼ״̬�ľ��루BFS�������Ľ�����ڲ�Σ� 
};

int encoding(Node* n) {
// �����n����Ϊһ����������ʾ����״̬��
	return n->a[0]*10000 + n->a[1]*100 + n->a[2];	
}

int bfs(Node* init, Node* end) {
// ��start��㿪ʼ�������������end״̬�� init��ˮ���ĳ�������,����end��start��̾��� 
	set<int> vis;		// vis�������Ѿ����ʹ��Ľ���״̬�� 
	queue<Node*> q;		// ���У�����bfs���������ڱ����ʵĽ��	
	Node* start = new Node();	
	start->a[0] = init->a[0];		// ��һ��ˮ�������� 
	start->a[1] = start->a[2] = 0;	// �ڶ�����ˮ���ǿյ� 
	start->d = 0;					// �������״̬Ϊ0 
	vis.insert(encoding(start));	// ��ǳ��Խ�����
	q.push(start);					// ���뵽��β
	
	while(!q.empty()) {	// ���зǿգ���ʾ��δ������Ľ��
		Node* u = q.front();		// ���ʶ�ͷԪ�� 
		q.pop();		// ������ͷԪ�� 
//		printf("%d-%d-%d-%d\n", u->d, u->a[0], u->a[1], u->a[2]);
		if(encoding(u)==encoding(end)) {	// �����Ⱦ��Ѿ��ҵ� 
			return u->d;
		}
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {	
				if(i!=j) {			// ö������iˮ����ˮ��jˮ�� 
					Node* w = new Node();	// w��u���ڽӾ��� 
					for(int k=0; k<3; k++) w->a[k] = u->a[k];	// ����һ�� 
					if(w->a[i] <= (init->a[j] - w->a[j])) {	// iˮ�����ˮС��jʣ������������ȫ������j 
						w->a[i] = 0;
//						w->a[j] = w->a[j] + w->a[i];
						w->a[j] = u->a[j] + u->a[i];	// ���ﲻ����w����Ϊ�����Ѿ��޸���w->a[i]=0�� 
					} else {	// ��jˮ������ 
						w->a[i] = w->a[i] - (init->a[j] - w->a[j]);
						w->a[j] = init->a[j];
					}
					w->d = u->d + 1;		// w�Ǵ�u���������ģ��������Ҫ��һ 
//					if(w->a[0]+w->a[1]+w->a[2] != init->a[0]) {
//						printf("%d->%d\n", i, j);
//						printf("%d-%d-%d-%d\n", u->d, u->a[0], u->a[1], u->a[2]);
//						printf("%d-%d-%d-%d\n", w->d, w->a[0], w->a[1], w->a[2]);
//						break;
//					}
					if(vis.find(encoding(w)) == vis.end()) {	// wû����vis�������� 
						q.push(w);				// �����β����Ƿ��� 
						vis.insert(encoding(w));
					}
				}
			}
		} 
	} 
	return -1;	// ��ʾendû���ҵ� 
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

