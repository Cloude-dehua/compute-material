#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 25;
int flag[maxn];

void shu(int& a, int t, int d, int n) {
// 在a上沿着d方向走t步
	while(t--) {	// 走t步 
		do{			// 走一步 
			a += d;	// 沿着d方向走 
			if(a>n) a = 1;	// 判断两端 
			if(a<1) a = n;
		} while(flag[a]);		// flag[a]==1表示a所指这个人不在队伍里面，这一步不算，继续走 
	}	
}
int main(){
	int n, k, m;
	while(scanf("%d%d%d", &n, &k, &m)==3) {
		memset(flag, 0, sizeof(flag));	// 初始化为0表示全部在队伍里面 
		int a = n, b = 1;	// 初始化所指位置
		int left = n;		// 队伍里剩余的人
		while(left>0) {		// 队伍里还有人 
			shu(a, k, 1, n);	// a从小往大数 
			shu(b, m, -1, n);	// b从大往小数 
			flag[a] = flag[b] = 1;	// 两个人出队，做逻辑删除 
			if(a==b) {
				printf("%d", a);	// 指向同一个人 
				left--;
			} else {	// 指向不同的人 
				printf("%d %d", a, b); 
				left -= 2;
			}
			if(left) printf(",");	// 逗号分隔一轮循环 
			else printf("\n");
		} 
	}

	return 0;
}

