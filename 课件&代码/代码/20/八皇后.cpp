/**
登登考研团队
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n = 8;
	int a[9];
	for(int i=1; i<=n; i++) {
		a[i] = i;
	} 
	int kase = 1;
	do{
		// a[i]=j 表示第i行第j列有一个Q(i, a[i])
		// 检查每个皇后的主副对角线上是否有其它皇后  
		bool ok = true;
		for(int i=1; i<=n && ok; i++) {	//  检查每两个皇后连线的斜率是否为1或者-1 
			for(int j=i+1; j<=n; j++) {
				///  (Y1-Y2)/(X1-X2) == 1 ,-1   
				if((a[i]-a[j] == i-j) || (a[i]-a[j] == j-i)) {	// 在同一条对角线上 
					ok = false;
					break;
				}
			}
		}
		if(ok) {
			printf("Case %d:\n", kase++);
			for(int i=1; i<=n ; i++) {
				for(int j=1; j<a[i]; j++) {
					printf("#");
				}
				printf("@");
				for(int j=a[i]+1; j<=n; j++) {
					printf("#");
				}
				printf("\n");
			}
		}
	} while(next_permutation(a+1, a+n+1));
	return 0;
}

