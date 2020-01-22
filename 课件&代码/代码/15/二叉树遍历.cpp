#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 30; 
char preOrder[maxn], inOrder[maxn];

struct BiNode{					// 二叉树结点定义 
	char data;					// 数据域 	
	BiNode* lchild, *rchild;		// 左右孩子指针域 
};
BiNode* build(int L1, int R1, int L2, int R2) {
// 根据先序preOrder[L1, R1]和中序inOrder[L2, R2]来递归构造二叉树，并返回根结点	
	if(L1>R1) return NULL;		// 空树
	BiNode* root = new BiNode();	// 构造根结点 
	root->data =  preOrder[L1];		
	int p = L2;		// 寻找更在中序遍历中的位置
	while(inOrder[p] != root->data) p++;
	int llen = p-L2;		// 左子树结点数量
	// 先序:L1[L1+1, L1+llen][L1+llen+1, R1], 中序[L2, p-1]p[p+1, R2] 
	root->lchild = build(L1+1, L1+llen, L2, p-1);	// 递归构造左子树 
	root->rchild = build(L1+llen+1, R1, p+1, R2);
	return root;
} 
void postOrder(BiNode* T) {
	if(T!=NULL) {	// 非空 
		postOrder(T->lchild);		// 后序遍历左子树 
		postOrder(T->rchild);		// 后序遍历右子树
		printf("%c", T->data);		// 遍历根 
	}
}

int main(){
	while(scanf("%s%s", preOrder, inOrder)==2) {
		int len = strlen(preOrder);		// 二叉树结点数量
		BiNode* root = build(0, len-1, 0, len-1);		// 构造二叉树
		postOrder(root);
		printf("\n");
	}
	return 0;
}

