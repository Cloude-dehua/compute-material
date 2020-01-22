#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 100 + 10;
int a[maxn];		// a保存所有人手中糖的数量 
int n;				// 人数 
bool isSame() {
// 判断n个人手里的糖是否一样
	for(int i=1; i<=n; i++) {
		if(a[i] != a[1]) return false;
	} 
	return true;
} 

int main(){
	
	while(scanf("%d", &n)==1) {
		for(int i=1; i<=n; i++) {	// 初始化每个人手里糖的数量 
			scanf("%d", &a[i]);
		}
		int ans = 0;			// 补发糖的数量 
		while(!isSame()) {			// 当他们手中的糖不完全一样，这模拟游戏 
			int tmp = a[1]; 		// a[1]当前手里的糖 
			// 将手里的糖分一半给编号小的（除了1号）
			for(int i=2; i<=n; i++) {
				a[i-1] += a[i]/2;
				a[i] /= 2; 
			} 
			a[n] += tmp/2;			// 当前a[1]的一半糖 
			a[1] -= tmp/2;			// a[1]自己拿出这轮游戏前一半的糖 
			
			// 补发糖		
			for(int i=1; i<=n; i++) {
				if(a[i]%2==1) {		// 奇数颗糖需要补发 
					a[i]++;
					ans++;
				}
			} 
		} 
		printf("%d\n", ans); 
	}
	return 0;
}

