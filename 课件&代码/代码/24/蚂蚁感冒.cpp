/**
登登考研团队
*/
#include <cstdio>
const int maxn = 60;
int a[maxn];
int main() {
	int n;
	while(scanf("%d", &n)==1) {
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		int cnt = 1;
		bool ok = false;
		for(int i=1; i<n; i++) {
			if(a[i]*a[0]<0) {	// 不是所有的蚂蚁方向都一样	
				ok = true; 
			}
			if(a[0]>0) {	// 第一只蚂蚁右， 
				if(a[i]>0 && a[i]<a[0]) {	//  在他左边的朝右
					cnt++;
				} else if(a[i]<0 && -a[i] > a[0]) {	// 和在他右边的朝左
					cnt++;
				}
			} else if(a[0]<0) { // 朝左 
				if(a[i]<0 && a[i]<a[0]) { // 在右边朝左
					cnt++;
				}  
				else if(a[i]>0 && a[i]<(-a[0])) { // 在他左边朝右 
					cnt++;
				}
			}
		}
		if(ok) printf("%d\n", cnt);
		else printf("1\n");
	}
	return 0;
}

