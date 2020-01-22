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
	for(int i=0; i<n; i++) {	// ö������a+b 
		for(int j=0; j<n; j++) {
			ab[cnt++] = a[i] + b[j];
		}
	}
	sort(ab, ab+cnt);		// ��a+b�ĺ�����
	int ans = 0; 
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int _cd = -(c[i]+d[j]);		// ��-(c[i]+d[j])��a+b�����г��ֵĴ���
			ans += upper_bound(ab, ab+cnt, _cd) - lower_bound(ab, ab+cnt, _cd);	// ��ѯ-(c+d)��a+b���ֵĵ�һ�κ����һ�� 
		}
	} 
	printf("%d\n", ans);
	return 0;
}

