#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000+10;
int a[maxn];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n);	// ������������a[0, n)��ֵ
	int ans = 0;
	for(int i=0; i<n-1; i++) {	// ����n-1�ϲ� 
		a[i+1] = a[i]+a[i+1];	// ѡ������������a[i, n)��ѡ����ǰ���ѽ��кϲ�����a[i+1] 
		ans += a[i+1];
		sort(a+i+1, a+n);	// ������������a[i+1, n)��ֵ
	} 
	printf("%d\n", ans);
	return 0;
}

