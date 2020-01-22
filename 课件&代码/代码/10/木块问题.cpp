#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;
typedef long long ll;

const int maxn = 5000+10;
vector<int> a[maxn];	// a[i]��һ����̬���飬�����i����ľͷ������ 
int n;
void myfind(int x, int& p, int& q) {
// ���ұ��xľ�����ھ���λ�ã�p�ѵĵ�q�� 
	for(int i=0; i<n; i++) {		// �������ж��ϵ�ľ�� 
		for(int j=0; j<a[i].size(); j++) {
			if(a[i][j] == x) {
				p = i;
				q = j;
				return;
			}
		}
	} 
}

void clear_above(int p, int q) {
// ��p��q�����������Ϸ���ľ��ȫ����λ 
	int c;
	for(int i=q+1; i<a[p].size(); i++) {
		c = a[p][i];			// �õ�q�Ϸ���ľ���� 
		a[c].push_back(c);		// ��λ 
	}
	a[p].resize(q+1);			// ������С��ֵ����[0, q]��ľ�� 
} 

void shift(int p, int h, int q) {
// ��p��h�����������ϵ�ľ��ȫ��һ����q���� 
	int c;
	for(int i=h; i<a[p].size(); i++) {
		c = a[p][i];			// �õ�q�Ϸ���ľ���� 
		a[q].push_back(c);		// ��λ 
	}
	a[p].resize(h);				// ������С��ֵ����[0, h)��ľ�� 
}

void print() {
		// ���
	for(int i=0; i<n; i++) {
		printf("%d:", i);
		for(int j=0; j<a[i].size(); j++) {
			printf(" %d", a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	
	scanf("%d", &n);
	for(int i=0; i<n; i++) {	// ��ʼʱÿ������ֻ�������ڱ�ŵ�ľ�� 
		a[i].push_back(i);		// ���ľ�� 
	}
	
	char cmd1[5], cmd2[2];
	int x, y;
	int xl, xh, yl, yh;		// x,��y���ڵľ���λ�� 
	while(scanf("%s", cmd1)==1 && strcmp(cmd1, "quit")!=0) {
		scanf("%d%s%d", &x, cmd2, &y);		
		myfind(x, xl, xh);
		myfind(y, yl, yh);
		if(xl == yl) continue;		// �Ƿ����������� 
		
		if(strcmp(cmd1, "move")==0) {	// ��a���ڶѵ�ah����ľ���λ 
			clear_above(xl, xh);
		}
		if(strcmp(cmd2, "onto")==0) {// ��b���ڶѵ�bh����ľ���λ 
			clear_above(yl, yh);
		}
		shift(xl, xh, yl);			// ֱ���ƶ� 
//		print();
	} 
 	print();
	
	return 0;
}

