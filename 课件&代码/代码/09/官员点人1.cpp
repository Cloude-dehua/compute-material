/**
登登考研团队
*/
#include <cstdio>
const int maxn = 25;
int vis[maxn];	// vis[i]==1表示编号为i的人在队列中，vis[i]==0已经不在啦 
int n, k, m;
// p表示当前的下标， d表示方向， x表示点过去几个人 
int dian(int p, int d, int x) {
	while(x--) {
		do{
			p += d;	
			if(p>n) p = 1;	// 因为是循环点人，检查是否越界 
			if(p<1) p = n;
		} while(vis[p]==0);	// 跳过已经被点去的人 
	}
	return p;
}
int main() {
	
	while(scanf("%d%d%d", &n, &k, &m)==3) {
		for(int i=1; i<=n; i++) vis[i] = 1;
//		memset(vis, 1, sizeof(vis));	// memset只能讲数组初始化为0和-1
		int left = n;	// 剩下的人
		int p1 = n;	// A官员当前指向的人
		int p2 = 1;	// B官员当前指向的人的编号 
		while(left>0) {
			p1 = dian(p1, 1, k);
			p2 = dian(p2, -1, m);
			vis[p1] = vis[p2] = 0;	// 把当前点到人标志为出去 
			printf("%d", p1);
			left--;
			if(p1!=p2) {	// 当A和B的点人不一样时，将B的人输出 
				printf(" %d", p2);
				left--;
			}
			if(left>0) printf(",");
		}
		printf("\n");	 
	}
	return 0;
}

