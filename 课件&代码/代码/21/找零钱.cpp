/**
登登考研团队
*/
#include <cstdio>
int a[] = {100, 50, 20, 10, 5, 1};	// 钞票面额 

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) ==2) {
		int cnt = 0; 
		int left = m - n;	// 要找的钱
		for(int i=0; i<6; i++) {	// 从面额大的钞票找起 
//			while(left>=a[i]) {	// 可以找a[i] 的钞票 
//				left -= a[i];
//				cnt++;
//			}
			cnt += left / a[i];	// 直接计算要找多少张面额为a[i]的钞票 
			left %= a[i];	// 找完后剩下的钱 
			if(left==0) break;
		} 
		printf("%d\n", cnt);
		
	}
	return 0;
}

