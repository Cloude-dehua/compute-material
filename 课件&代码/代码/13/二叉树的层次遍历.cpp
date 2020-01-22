#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;

struct BiNode{		// 二叉树结点定义 
	int data;		// 数据域 
	BiNode* lchild;	// 左孩子
	BiNode* rchild;	// 右孩子
	bool valued;		// 标记这个结点是否被赋值过了
	
	BiNode() {		// 构造函数，对成员变量做初始化 
		data = 0;
		lchild = rchild = NULL;
		valued = false;
	} 
};


BiNode* root;	// 根结点 
bool ok = true;	// 标记每个结点有且仅被赋值一次 
void addNode(int data, char* s) {
// 根据移动序列s将数据域为data的结点挂载到二叉树
	BiNode* p = root;		// p是扫描指针 
	int len = strlen(s);
	for(int i=0; i<len; i++) {
		if(s[i]=='L') {			// 往左走 
			if(p->lchild==NULL) p->lchild = new BiNode();		// 如果左孩子不存在 
			p = p->lchild;
		} else if(s[i]=='R') {	// 往右走 
			if(p->rchild==NULL) p->rchild = new BiNode();
			p = p->rchild;
		}
	}
	if(p->valued) ok = false;		// 如果当前结点已经被赋值过了
	p->data = data;					// 初始化p数据 
	p->valued = true; 
}

bool read() {
// 读入一组数据，然后构造二叉树，如果成功构造返回true
	char s[300];			// 接收一个结点
	root = new BiNode(); 	// 创建根结点
	ok = true;				// 初始化ok 
	while(1) {				// 每次接收一个数据 
		if(scanf("%s", s)!=1) return false;		// 没有数据了 
		if(strcmp("()", s)==0) return true;		// 一组数据成功接收完成 
		// (11,LL) 
		// 解析数字
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

vector<int> ans;		// 保存层次遍历过程中的值 
void bfs() {
// 层次遍历二叉树
	queue<BiNode*> q;	// 队列
	q.push(root);		// 加入根结点
	ans.clear();		// 清空上一次的保存的数据 
	while(!q.empty()) {	// 队列非空，一直遍历 
		BiNode* u = q.front();		// 访问队首元素 
		q.pop();					// 弹出队首元素
//		visit(u);
		ans.push_back(u->data);		// 添加层次遍历序列 
		if(!u->valued) ok = false;				// 这个结点没有赋值 
		if(u->lchild) q.push(u->lchild);		// 如果有左孩子，加入队尾 
		if(u->rchild) q.push(u->rchild);		// 如果有右孩子，加入队尾 
	} 
}

int main(){
	while(read()) {		// 一直做输入 
		bfs();
		if(ok) {	// 如果每个结点有且仅被赋值一次 
			for(int i=0; i<ans.size(); i++) {		// 输出ans 
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

