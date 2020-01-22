#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;

struct BiNode{		// ��������㶨�� 
	int data;		// ������ 
	BiNode* lchild;	// ����
	BiNode* rchild;	// �Һ���
	bool valued;		// ����������Ƿ񱻸�ֵ����
	
	BiNode() {		// ���캯�����Գ�Ա��������ʼ�� 
		data = 0;
		lchild = rchild = NULL;
		valued = false;
	} 
};


BiNode* root;	// ����� 
bool ok = true;	// ���ÿ��������ҽ�����ֵһ�� 
void addNode(int data, char* s) {
// �����ƶ�����s��������Ϊdata�Ľ����ص�������
	BiNode* p = root;		// p��ɨ��ָ�� 
	int len = strlen(s);
	for(int i=0; i<len; i++) {
		if(s[i]=='L') {			// ������ 
			if(p->lchild==NULL) p->lchild = new BiNode();		// ������Ӳ����� 
			p = p->lchild;
		} else if(s[i]=='R') {	// ������ 
			if(p->rchild==NULL) p->rchild = new BiNode();
			p = p->rchild;
		}
	}
	if(p->valued) ok = false;		// �����ǰ����Ѿ�����ֵ����
	p->data = data;					// ��ʼ��p���� 
	p->valued = true; 
}

bool read() {
// ����һ�����ݣ�Ȼ���������������ɹ����췵��true
	char s[300];			// ����һ�����
	root = new BiNode(); 	// ���������
	ok = true;				// ��ʼ��ok 
	while(1) {				// ÿ�ν���һ������ 
		if(scanf("%s", s)!=1) return false;		// û�������� 
		if(strcmp("()", s)==0) return true;		// һ�����ݳɹ�������� 
		// (11,LL) 
		// ��������
		int len = strlen(s);
		int num = 0;
		for(int i=0; i<len; i++) {	
			if('0'<=s[i] && s[i]<='9') {
				num = num*10+s[i]-'0';
			}
		} 
//		printf("data=%d\n", num);
		addNode(num, s);
	} 	
}

vector<int> ans;		// �����α��������е�ֵ 
void bfs() {
// ��α���������
	queue<BiNode*> q;	// ����
	q.push(root);		// ��������
	ans.clear();		// �����һ�εı�������� 
	while(!q.empty()) {	// ���зǿգ�һֱ���� 
		BiNode* u = q.front();		// ���ʶ���Ԫ�� 
		q.pop();					// ��������Ԫ��
//		visit(u);
		ans.push_back(u->data);		// ��Ӳ�α������� 
		if(!u->valued) ok = false;				// ������û�и�ֵ 
		if(u->lchild) q.push(u->lchild);		// ��������ӣ������β 
		if(u->rchild) q.push(u->rchild);		// ������Һ��ӣ������β 
	} 
}

int main(){
	while(read()) {		// һֱ������ 
		bfs();
		if(ok) {	// ���ÿ��������ҽ�����ֵһ�� 
			for(int i=0; i<ans.size(); i++) {		// ���ans 
				if(i>0) printf(" ");
				printf("%d", ans[i]);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	} 

	return 0;
}

