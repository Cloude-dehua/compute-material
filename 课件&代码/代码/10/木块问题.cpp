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
vector<int> a[maxn];	// a[i]是一个动态数组，保存第i堆中木头的数量 
int n;
void myfind(int x, int& p, int& q) {
// 查找编号x木块所在具体位置：p堆的第q个 
	for(int i=0; i<n; i++) {		// 遍历所有堆上的木块 
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
// 将p堆q（不包含）上方的木块全部归位 
	int c;
	for(int i=q+1; i<a[p].size(); i++) {
		c = a[p][i];			// 拿到q上方的木块编号 
		a[c].push_back(c);		// 归位 
	}
	a[p].resize(q+1);			// 调整大小，值保留[0, q]的木块 
} 

void shift(int p, int h, int q) {
// 将p堆h（包含）以上的木块全部一定到q堆上 
	int c;
	for(int i=h; i<a[p].size(); i++) {
		c = a[p][i];			// 拿到q上方的木块编号 
		a[q].push_back(c);		// 归位 
	}
	a[p].resize(h);				// 调整大小，值保留[0, h)的木块 
}

void print() {
		// 输出
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
	for(int i=0; i<n; i++) {	// 初始时每个堆上只有他对于编号的木块 
		a[i].push_back(i);		// 添加木块 
	}
	
	char cmd1[5], cmd2[2];
	int x, y;
	int xl, xh, yl, yh;		// x,和y所在的具体位置 
	while(scanf("%s", cmd1)==1 && strcmp(cmd1, "quit")!=0) {
		scanf("%d%s%d", &x, cmd2, &y);		
		myfind(x, xl, xh);
		myfind(y, yl, yh);
		if(xl == yl) continue;		// 非法操作，忽略 
		
		if(strcmp(cmd1, "move")==0) {	// 将a所在堆的ah以上木块归位 
			clear_above(xl, xh);
		}
		if(strcmp(cmd2, "onto")==0) {// 将b所在堆的bh以上木块归位 
			clear_above(yl, yh);
		}
		shift(xl, xh, yl);			// 直接移动 
//		print();
	} 
 	print();
	
	return 0;
}

