/**
登登考研团队
*/
#include <cstdio>

int main() {
	int k, y;
	int kase = 1;
	while(scanf("%d", &k)==1) {
		printf("Case %d:\n", kase++);
		for(y=k+1; y<=2*k; y++) {	// 确定y的枚举范围 
			// x = y*k/(y-k) 
			if((y*k) % (y-k) == 0) {	// x是整数 
				printf("1/%d=1/%d+1/%d\n", k, (y*k)/(y-k), y);
			}	
		}
	}
	return 0;
}

