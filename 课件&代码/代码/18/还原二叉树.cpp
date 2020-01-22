#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 40;
int level[maxn], inOrder[maxn];	// ��α����������������
struct Node{		// ��������� 
	int data;		// ������
	Node* left;		// ����
	Node* right;	// �Һ��� 
};

Node* build(int* level, int* inOrder, int L, int R) {
// ���ݲ�α�������level�������������inOrder[L,R]���ݹ鹹������������ظ����
	if(L>R) return NULL;	// �������ݹ����
	Node* root = new Node();	// ����� 
	root->data = level[0];	// ��α����ĵ�һ�������Ǹ����
	int ind;	// ���������������е�λ�� 
	for(ind=L; ind<R; ind++) {	// ����������в��� 
		if(inOrder[ind]==root->data) {	// �ҵ������ 
			break;
		}
	} 
	// ����[L,ind-1]ind[ind+1,R] 
	int llen = ind-L;	// �������ĳ���
	int rlen = R-ind;	// �������ĳ���
	int llevel[llen];	// �������Ĳ�α��� 
	int rlevel[rlen]; 
	int lcnt=0, rcnt = 0;	// ��α������ֹ��������Һ��ӽ������ 
	for(int i=1; i<(R-L+1); i++) {	// ������������е�ÿһ����� 
		int inLeft = 0;			// �߽�level[i]�������������� 
		for(int j=L; j<ind; j++) {	// ������������ 
			if(level[i]==inOrder[j]) {	// �ҵ��� 
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
	root->left = build(llevel, inOrder, L, ind-1);	// �ݹ鹹�������� 
	root->right = build(rlevel, inOrder, ind+1, R);	// �ݹ鹹��������
	return root;	// ���ظ� 
}

int first = 1;	// ��ǵ�һ����ӡ 
void preOrder(Node* T) {
// �������������T 
	if(T!=NULL) {	// ���ǿ� 
		if(first==0) printf(" ");
		first = 0;
		printf("%d", T->data);	// �ȱ����� 
		preOrder(T->left);		// ������������� 
		preOrder(T->right);		// �������������
	}
}

void postOrder(Node* T) {
// ���������������T 
	if(T!=NULL) {	// ���ǿ� 
		postOrder(T->left);		// ������������� 
		postOrder(T->right);	// �������������
		if(first==0) printf(" ");
		first = 0;
		printf("%d", T->data);	// �ȱ����� 
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &level[i]);
	for(int i=0; i<n; i++) scanf("%d", &inOrder[i]); 
	Node* root = build(level, inOrder, 0, n-1);		// ���������
	preOrder(root);
	printf("\n");
	first = 1;
	postOrder(root);
	printf("\n");
	return 0;
}

