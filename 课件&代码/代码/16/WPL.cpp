#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000;
int w[maxn];	// w[i]��ʾi����Ȩֵ 
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &w[i]); 
	} 
	sort(w, w+n);	// ������w[0, n)��������
	int ans = 0;	// ͳ�ƺϲ������еĽ��Ȩֵ 
	for(int i=0; i<n-1; i++) {	// ����n-1�κϲ� 
		w[i+1] = w[i] + w[i+1];	// w[i, n) ==> w[i+1, n)
		ans += w[i+1];
		sort(w+i+1, w+n);
	} 
	printf("%d\n", ans);
	return 0;
}

