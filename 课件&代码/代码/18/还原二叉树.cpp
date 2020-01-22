#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 40;
int level[maxn], inOrder[maxn];	// 层次遍历和中序遍历序列
struct Node{		// 二叉树结点 
	int data;		// 数据域
	Node* left;		// 左孩子
	Node* right;	// 右孩子 
};

Node* build(int* level, int* inOrder, int L, int R) {
// 根据层次遍历序列level和中序遍历序列inOrder[L,R]来递归构造二叉树，返回根结点
	if(L>R) return NULL;	// 空树，递归遍历
	Node* root = new Node();	// 根结点 
	root->data = level[0];	// 层次遍历的第一个结点就是根结点
	int ind;	// 根结点在中序遍历中的位置 
	for(ind=L; ind<R; ind++) {	// 在中序遍历中查找 
		if(inOrder[ind]==root->data) {	// 找到根结点 
			break;
		}
	} 
	// 中序[L,ind-1]ind[ind+1,R] 
	int llen = ind-L;	// 左子树的长度
	int rlen = R-ind;	// 右子树的长度
	int llevel[llen];	// 左子树的层次遍历 
	int rlevel[rlen]; 
	int lcnt=0, rcnt = 0;	// 层次遍历划分过程中左右孩子结点数量 
	for(int i=1; i<(R-L+1); i++) {	// 遍历层次序列中的每一个结点 
		int inLeft = 0;			// 边界level[i]是在在左子树中 
		for(int j=L; j<ind; j++) {	// 到左子树中找 
			if(level[i]==inOrder[j]) {	// 找到了 
				inLeft = 1;
				break;
			}
		}
		if(inLeft) {
			llevel[lcnt++] = level[i];
		} else {
			rlevel[rcnt++] = level[i];
		}
	} 
	root->left = build(llevel, inOrder, L, ind-1);	// 递归构造左子树 
	root->right = build(rlevel, inOrder, ind+1, R);	// 递归构造左右树
	return root;	// 返回根 
}

int first = 1;	// 标记第一个打印 
void preOrder(Node* T) {
// 先序遍历二叉树T 
	if(T!=NULL) {	// 树非空 
		if(first==0) printf(" ");
		first = 0;
		printf("%d", T->data);	// 先遍历根 
		preOrder(T->left);		// 先序遍历左子树 
		preOrder(T->right);		// 先序遍历右子树
	}
}

void postOrder(Node* T) {
// 后序序遍历二叉树T 
	if(T!=NULL) {	// 树非空 
		postOrder(T->left);		// 后序遍历左子树 
		postOrder(T->right);	// 后序遍历右子树
		if(first==0) printf(" ");
		first = 0;
		printf("%d", T->data);	// 先遍历根 
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &level[i]);
	for(int i=0; i<n; i++) scanf("%d", &inOrder[i]); 
	Node* root = build(level, inOrder, 0, n-1);		// 构造二叉树
	preOrder(root);
	printf("\n");
	first = 1;
	postOrder(root);
	printf("\n");
	return 0;
}

