#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 100000 + 10;
int Left[maxn];			// left[i]==j 表示i的前驱是j 
int Right[maxn]; 		// left[i]==j 表示i的后继是j
// 链表：1 3 5 4 6 2  
// left: 0 6 1 5 3 1
//Right: 3 0 5 6 4 2 

void link(int x, int y) {
// 链接x和y，x在y的左边
	Left[y] = x;
	Right[x] = y;	
}

int main(){
	int n,m;
	int kase = 1;
	while(scanf("%d%d", &n, &m)==2) {
		memset(Left, 0, sizeof(Left));
		memset(Left, 0, sizeof(Right));
		// 初始化Left和Right数组
		for(int i=1; i<=n; i++) {
			Left[i] = i-1;
			Right[i] = (i+1)%(n+1);		// Right[n] = 0，所以要取余 
		} 
		
		Left[0] = n;		// 将0作为头结点，这样就变成双向循环链表 
		Right[0] = 1;
		int rev = 0;		// 标记当前链表是否反转（反转操作只修改这个值，做逻辑上反转） 
		int op, x, y; 
		while(m--) {		// 模拟m次操作
			 scanf("%d", &op);
			 if(op==4) {	// 反转链表 
			 	rev = 1-rev;
			 } else {
			 	scanf("%d%d", &x, &y);	// 操作x和y盒子
				if(rev && op<3) op = 3 - op;		// 在反转情况下，x引动到y的左边和正的情况x引动到y的右边相同 
				// 1 x y 如果x已经在y的左边则忽略此命令 
				if(op == 1 && x==Left[y]) continue;		// 忽略
				if(op == 2 && x==Right[y]) continue; 
			 	
			 	int lx = Left[x], rx = Right[x], ly = Left[y], ry = Right[y];	// 拿到x和y的左右结点
				if(op==1) {	// 1 x y 表示把盒子x移动到盒子y的左边   lx x rx...ly y ry ==> lx rx... ly x y ry
					link(lx, rx);
					link(ly, x);
					link(x, y);
				} else if(op ==2) {	// 2 x y 表示把盒子x移动到盒子y的右边 lx x rx...ly y ry ==> lx rx... ly y x ry
					link(lx, rx);
					link(y, x);
					link(x, ry);
				} else if(op == 3) {// 3 x y 表示交换盒子x和y的位置
					if(Left[x] == y) {			//ly y x rx ==> ly x y rx
						link(ly, x);
						link(x, y);
						link(y, rx);
					} else if(Right[x] == y) {	//lx x y ry ==> lx y x ry 
						link(lx, y);
						link(y, x);
						link(x, ry);
					} else {					// lx x rx...ly y ry ==> lx y rx...ly x ry
						link(lx, y);
						link(y, rx);
						link(ly, x);
						link(x, ry);
					}
				}
			}
		}
		ll ans = 0;
		int j = 1;
		for(int i = Right[0]; i!=0 ; i = Right[i]) {	// 扫描整个链表 
			if(j%2==1) {	// 累加奇数位置的 
				ans= ans + (ll)i;
			}
			j++;
		} 
		if(rev && n%2==0) {	// 在反转和元素个数为偶数的情况，奇偶位置交换 
			ans = (ll)n*(1+n)/2 - ans;
		}
		printf("Case %d: %lld\n",kase++, ans);
	}

	return 0;
}

