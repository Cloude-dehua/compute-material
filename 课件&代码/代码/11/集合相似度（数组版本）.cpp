#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int ss[55][110];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int m;
		scanf("%d", &m);
		int cnt = 0;		// ss[i]中元素的个数 
		for(int j=0; j<m; j++) {
			int x;
			scanf("%d", &x);
			int flag = 0;		// 标记x是否在ss[i]中 
			for(int k=1; k<=cnt; k++) {	// 在ss[i]查找x 
				if(ss[i][k]==x) {
					flag = 1;
					break;
				}
			}
			if(!flag) {
				ss[i][++cnt] = x; 
			}
		}
		ss[i][0] = cnt;		// 保存长度 
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		int sameElem = 0;
		for(int i=1; i<=ss[a][0]; i++) {		// 枚举a集合中的元素 
			for(int j=1; j<=ss[b][0]; j++) {		// 枚举b集合中的元素
				if(ss[a][i] == ss[b][j]) {		// 如果相同 
					sameElem++;
				}
			}
		}
		int UElem = ss[a][0] + ss[b][0] - sameElem;
		printf("%.1lf%\n", 100.0 * sameElem/UElem);
	}

	return 0;
}

