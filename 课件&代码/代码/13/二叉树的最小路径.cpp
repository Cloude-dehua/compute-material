#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
int lch[maxn], rch[maxn];		// lch[i]==j��ʾ���i������Ϊj 
char s[maxn*4];
int inOrder[maxn];		// ��������
int postOrder[maxn];	// ����
int cnt = 0;			// ���г��� 

void parse(char*s, int* a, int& cnt) {
// ��һ���������ֵ��ַ�������Ϊcnt�����ֱ�����a������
	int len = strlen(s);
	int num = 0;
	cnt = 0; 
	for(int i=0; i<len; i++) {
		if('0'<=s[i] && s[i]<='9') {		// �������� 
			num = num*10 + s[i]-'0';
		} else {							// �����ո�ָ� 
			a[cnt++] = num;					// ��num���浽a�� 
			num = 0;						// ���³�ʼʱΪ0�����������һ������ 
		}
	}
	if('0'<=s[len-1] && s[len-1]<='9') a[cnt++] = num;		// ���һ��������Ҫ�ڱ��� 
}

int build(int L1, int R1, int L2, int R2) {
// ������������inOrder[L1, R1]�ͺ�������postOrder[L2, R2]���ݹ鹹����������Żظ����	
	if(L1>R1) return 0;			// ���� 
	int root = postOrder[R2];	// ����� 
//	printf("%d\n", root); 
	int p = L1;					// �������и����λ�� 
	while(inOrder[p]!=root) p++;	// �������������� 
	int llen = p-L1;			// ����������
	// ����[L1, p-1]p[p+1,R1],����[L2,L2+llen-1][L2+llen,R2-1]R2 
	lch[root] = build(L1, p-1, L2, L2+llen-1);	// �ݹ鹹�������� 
	rch[root] = build(p+1, R1, L2+llen, R2-1);	// �ݹ鹹��������
	return root;		// ���ظ���� 
}

int minSum = maxn*maxn;		// ��СȨֵ�� 
int ans = 0;				// Ŀ��Ҷ�ӽ�� 
void preOrder(int u, int sum) {
// ���������������u�ǵ�ǰ������㣬sum�Ǹ���㵽u��·��Ȩֵ��
	if(u!=0) {	// �ǿ� 
		sum += u;	// �ۼ�Ȩֵ
		if(lch[u]==0 && rch[u]==0) {	// Ҷ�ӽ�� 
			if(sum<minSum||(sum==minSum && u<sum)) {		// �������Ž� 
				minSum = sum;
				ans = u;
			}	
		}
		preOrder(lch[u], sum);		//������������� 
		preOrder(rch[u], sum);		//�������������
	} 
} 

int main(){
	while(gets(s)!=NULL) {
		memset(lch, 0, sizeof(lch));				// ��ʼ�� 
		memset(rch, 0, sizeof(rch)); 
		minSum = maxn*maxn;
		ans = 0;
		
		parse(s, inOrder, cnt);
		gets(s);
		parse(s, postOrder, cnt);
		
//		for(int i=0; i<cnt; i++) printf("%d-%d\n", inOrder[i], postOrder[i]); 
		
		int root = build(0, cnt-1, 0, cnt-1);		// ���������
		
		preOrder(root, 0);
		printf("%d\n", ans); 
	}

	return 0;
}

