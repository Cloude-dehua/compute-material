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
// ��ʽͼ�������⣺·���Ƿ�ɴ���·��
// ״̬����ͼ�е�һ�����㣬״ֱ̬��ת������ͼ��һ���� 
struct Node{	// ÿ���������е�״̬����Ӧͼ�еĶ��� 
	int a[9];		// ������Ĳ�����Ϣ
	int d;			// d��ʾ���ʼ������ľ��� 
};
int dr[] = {-1, 1, 0, 0};	// r����������:�������� 
int dc[] = {0, 0, -1, 1};


void print(Node* u) {
	printf("%d\n", u->d);
	for(int i=0; i<9; i++) {
		printf("%3d", u->a[i]);
		if((i+1)%3==0) printf("\n");
	}
}

int encoding(Node* u) {
// ��״̬u��a��9������ֱ��ƴ�ӳ�һ������ 
	int code = 0;
	for(int i=0; i<9; i++) {
		code = code*10+u->a[i];
	}
	return code; 
} 
int bfs(Node* start, Node* end) {
	queue<Node*> q;		// �������ڷ��ʵĶ���
	q.push(start);
	set<int> vis;				// �����ʹ��Ľ����뱣����set��������
	vis.insert(encoding(start));		// ���start���� 
	while(!q.empty()) {
		Node* u = q.front();
		q.pop();
//		print(u);
		// ���u�Ƿ���end
		int ok = 1;
		for(int i=0; i<9; i++) {
			if(u->a[i]!=end->a[i]) {
				ok = 0;
				break;
			}
		}
		if(ok) {	// �ҵ�end�� 
			return u->d;
		}
		int z, zr, zc;	// 0������λ�ú��к����к�
		for(int i=0; i<9; i++) {
			if(u->a[i]==0) {
				z = i;
				zr = i / 3;
				zc = i % 3;
				break;
			}
		} 
		for(int i=0; i<4; i++) {	// ����0���ĸ��������� 
			int newr = zr+dr[i];	// �ھӽ��0��λ�� 
			int newc = zc+dc[i];
			int newz = newr*3+newc;
//			printf("newr=%d, zr=%d, newc=%d, zc=%d\n", newr, zr, newc, zc);
			if(0<=newr && newr<3 && 0<=newc && newc<3) {
				Node* w = new Node();
				for(int j=0; j<9; j++) w->a[j] = u->a[j];	// ����ԭ����u��״̬����Ϊֻ��0�����Աߵ����ֽ����ˣ��󲿷�û�ж���	
				w->a[newz] = u->a[z];		// ����0�����Աߵ�һ������ 
				w->a[z] = u->a[newz];
				w->d = u->d + 1;			// ��μ�һ 
//				print(w); 
				if(vis.find(encoding(w))==vis.end()) {	// w����vis�У���û�з��ʹ� 
					vis.insert(encoding(w));	// ����Ӷ�βǰ�ȽϷ��� 
					q.push(w);					// ��Ӷ�β
				} 
			}
		}
	}
	return -1;		// û���ҵ�end 
}

int main(){
	Node* start = new Node();		// ��ʼ״̬
	Node* end = new Node();			// Ŀ��״̬
	for(int i=0; i<9; i++) scanf("%d", &start->a[i]); 
	for(int i=0; i<9; i++) scanf("%d", &end->a[i]);
	start->d = 0;
	printf("%d\n", bfs(start, end));
	return 0;
}

