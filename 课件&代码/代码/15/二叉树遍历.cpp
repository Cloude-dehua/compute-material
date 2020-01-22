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

struct BiNode{					// ��������㶨�� 
	char data;					// ������ 	
	BiNode* lchild, *rchild;		// ���Һ���ָ���� 
};
BiNode* build(int L1, int R1, int L2, int R2) {
// ��������preOrder[L1, R1]������inOrder[L2, R2]���ݹ鹹��������������ظ����	
	if(L1>R1) return NULL;		// ����
	BiNode* root = new BiNode();	// �������� 
	root->data =  preOrder[L1];		
	int p = L2;		// Ѱ�Ҹ�����������е�λ��
	while(inOrder[p] != root->data) p++;
	int llen = p-L2;		// �������������
	// ����:L1[L1+1, L1+llen][L1+llen+1, R1], ����[L2, p-1]p[p+1, R2] 
	root->lchild = build(L1+1, L1+llen, L2, p-1);	// �ݹ鹹�������� 
	root->rchild = build(L1+llen+1, R1, p+1, R2);
	return root;
} 
void postOrder(BiNode* T) {
	if(T!=NULL) {	// �ǿ� 
		postOrder(T->lchild);		// ������������� 
		postOrder(T->rchild);		// �������������
		printf("%c", T->data);		// ������ 
	}
}

int main(){
	while(scanf("%s%s", preOrder, inOrder)==2) {
		int len = strlen(preOrder);		// �������������
		BiNode* root = build(0, len-1, 0, len-1);		// ���������
		postOrder(root);
		printf("\n");
	}
	return 0;
}

