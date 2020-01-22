#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
int lch[maxn], rch[maxn];		// lch[i]==j表示结点i的左孩子为j 
char s[maxn*4];
int inOrder[maxn];		// 中序序列
int postOrder[maxn];	// 后序
int cnt = 0;			// 序列长度 

void parse(char*s, int* a, int& cnt) {
// 将一个包含数字的字符串解析为cnt个数字保存在a数组中
	int len = strlen(s);
	int num = 0;
	cnt = 0; 
	for(int i=0; i<len; i++) {
		if('0'<=s[i] && s[i]<='9') {		// 遇到数字 
			num = num*10 + s[i]-'0';
		} else {							// 遇到空格分割 
			a[cnt++] = num;					// 将num保存到a中 
			num = 0;						// 重新初始时为0，方便解析下一个数字 
		}
	}
	if('0'<=s[len-1] && s[len-1]<='9') a[cnt++] = num;		// 最后一个数字需要在保存 
}

int build(int L1, int R1, int L2, int R2) {
// 根据中序序列inOrder[L1, R1]和后序序列postOrder[L2, R2]来递归构造二叉树，放回根结点	
	if(L1>R1) return 0;			// 空树 
	int root = postOrder[R2];	// 根结点 
//	printf("%d\n", root); 
	int p = L1;					// 中序序列根结点位置 
	while(inOrder[p]!=root) p++;	// 在中序序列中找 
	int llen = p-L1;			// 左子树长度
	// 中序[L1, p-1]p[p+1,R1],后序[L2,L2+llen-1][L2+llen,R2-1]R2 
	lch[root] = build(L1, p-1, L2, L2+llen-1);	// 递归构造左子树 
	rch[root] = build(p+1, R1, L2+llen, R2-1);	// 递归构造右子树
	return root;		// 返回根结点 
}

int minSum = maxn*maxn;		// 最小权值和 
int ans = 0;				// 目标叶子结点 
void preOrder(int u, int sum) {
// 先序遍历二叉树，u是当前遍历结点，sum是根结点到u的路径权值和
	if(u!=0) {	// 非空 
		sum += u;	// 累加权值
		if(lch[u]==0 && rch[u]==0) {	// 叶子结点 
			if(sum<minSum||(sum==minSum && u<sum)) {		// 遇到更优解 
				minSum = sum;
				ans = u;
			}	
		}
		preOrder(lch[u], sum);		//先序遍历左子树 
		preOrder(rch[u], sum);		//先序遍历右子树
	} 
} 

int main(){
	while(gets(s)!=NULL) {
		memset(lch, 0, sizeof(lch));				// 初始化 
		memset(rch, 0, sizeof(rch)); 
		minSum = maxn*maxn;
		ans = 0;
		
		parse(s, inOrder, cnt);
		gets(s);
		parse(s, postOrder, cnt);
		
//		for(int i=0; i<cnt; i++) printf("%d-%d\n", inOrder[i], postOrder[i]); 
		
		int root = build(0, cnt-1, 0, cnt-1);		// 构造二叉树
		
		preOrder(root, 0);
		printf("%d\n", ans); 
	}

	return 0;
}

