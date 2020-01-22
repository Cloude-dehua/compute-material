#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 4000 + 10;
int a[maxn], b[maxn], c[maxn], d[maxn], ab[maxn*maxn];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
	}
	int cnt = 0;
	for(int i=0; i<n; i++) {	// 枚举所有a+b 
		for(int j=0; j<n; j++) {
			ab[cnt++] = a[i] + b[j];
		}
	}
	sort(ab, ab+cnt);		// 对a+b的和排序
	int ans = 0; 
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int _cd = -(c[i]+d[j]);		// 找-(c[i]+d[j])在a+b集合中出现的次数
			ans += upper_bound(ab, ab+cnt, _cd) - lower_bound(ab, ab+cnt, _cd);	// 查询-(c+d)在a+b出现的第一次和最后一次 
		}
	} 
	printf("%d\n", ans);
	return 0;
}

