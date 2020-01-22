#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
int b[maxn];	// 参加复试人的分数数组
int cnt = 0;	// 参加复试人的数量 

bool cmp(int a, int b) {
	return a>b;		// 降序 
}

int main(){
	int n;			// 参加初试的人数 
	scanf("%d", &n);
	int line[5];	// 五个分数线
	for(int i=0; i<5; i++) scanf("%d", &line[i]);
	for(int i=0; i<n; i++) {	// 处理n个同学 
		int a[5];
		a[4] = 0;	// 总分 
		for(int i=0; i<4; i++) {
			scanf("%d", &a[i]);
			a[4] += a[i];		// 累加单科成绩 
		}
		bool ok = 1;		// 标记当前考上是否能进入复试 
		for(int i=0; i<5; i++) {
			if(a[i] < line[i]) {	// 第i科没有过线 
				ok = 0;
				break;
			}
		}
		if(ok) {	// 进入复试 
			b[cnt++] = a[4];
		} 
	} 
	
	sort(b, b+cnt, cmp);		// 根据cmp规则排序b[0, cnt)，若没有cmp则升序 
	// 逆序输出 
//	for(int i=cnt-1; i>=0; i--) {
//		printf("%d\n", b[i]);	
//	}
	for(int i=0; i<cnt; i++) {
		printf("%d\n", b[i]);
	} 
	return 0;
}

