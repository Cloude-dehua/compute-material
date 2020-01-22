#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int maxn = 55;
set<int> ss[maxn]; 
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int m, x;
		scanf("%d", &m);
		for(int j=0; j<m; j++) {
			scanf("%d", &x);
			if(ss[i].find(x) == ss[i].end()) {	// 在第i个set中找x，如果放回end()表示没有找到 
				ss[i].insert(x);
			}
		}
	}	
	int q;
	scanf("%d", &q);
	while(q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--; 
		int sameElem = 0; 		// 交集元素个数 
		for(set<int>::iterator it = ss[a].begin(); it != ss[a].end(); it++) {	// 遍历集合 
			if(ss[b].find(*it) != ss[b].end()) {  //拿着a集合中的元素it到b集合中查找，如果在b中，即为交集元素 
				sameElem++;					
			}
		}
		int UElem = ss[a].size() + ss[b].size() - sameElem;		// 并集个数
		printf("%.1lf%\n", 100.0 * sameElem/UElem); 
		
	}

	return 0;
}

