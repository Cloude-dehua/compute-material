/**
登登考研团队
*/
#include <cstdio>
#include <algorithm>
using namespace std;
 
const int maxn = 2000 + 10; 
int nong[maxn];	// 龙 
int qi[maxn];	// 骑士能力 
int main() {
	int n , m;
	while(scanf("%d%d", &n, &m) == 2 && !(n==0 && m==0)) {
		for(int i=0; i<n; i++) scanf("%d", &nong[i] );
		for(int i=0; i<m; i++) scanf("%d", &qi[i]);
		sort(nong, nong+n);
		sort(qi, qi+m);
		int j = 0;
		int ans = 0;	// 总佣金 
		for(int i=0; i<m; i++) {// 从能力低到高来考虑每个骑士是否雇佣 
			if(qi[i]>=nong[j]) {
				j++;	// 砍下一条龙
				ans += qi[i];	// 
				if(j==n) break;	// 已经砍完 
			}
		}
		if(j==n) {
			printf("%d\n", ans); 
		} else {
			printf("No\n");
		}
		 
	} 
	return 0;
}

