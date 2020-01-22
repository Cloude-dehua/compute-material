#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 20;
int a[1<<maxn];			// a数组保存所有节点的状态，a[i]==0表示关闭 

int main(){
	int d, n;	// 二叉树的深度和猴子数量
	while(scanf("%d%d", &d, &n)==2 && !(d==0 && n==0)) {
		memset(a, 0, sizeof(a));		// 初始化所有开关都是关闭的
		// 模拟n的猴子
		int k;
		for(int i=0; i<n; i++) {
			k = 1;				// 表示当前所在节点，初试试在根节点上 
			for(int j=1; j<d; j++) {	// 往下走d-1层 
				a[k] = !a[k];		// 修改节点状态
				if(a[k]==1) {		// 修改前状态为0，往左走 
					k = 2*k;		// k的左孩子编号 
				} else {			// 右走 
					k = 2*k+1;
				}
			} 	
		} 
		printf("%d\n", k);		//	最后一个猴子所在叶子节点的编号 
		
	}

	return 0;
}

