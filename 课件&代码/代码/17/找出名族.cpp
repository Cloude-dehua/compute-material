#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 10000 + 10;
int f[maxn];		// f[i]��ʾi���ĸ��ڵ㣬f[i]==iΪ����� 
int find(int a) {
// ����a����������ĸ�
	return a==f[a] ? a : f[a] = find(f[a]);		// ��·��ѹ�����ң�������·���ϵĽ�㶼ֱ�ӹ����ڸ�������� 
}
int main(){

	int n, m;
	while(scanf("%d%d", &n, &m)==2 && !(n==0 && m==0)) {	// n����(ͼ�еĽ��), m��ͬ�����ϵ��ͼ�еıߣ�
		for(int i=1; i<=n; i++) f[i] = i;	// ÿ����㶼��һ����ͨ�飨���ϡ�����
		int a, b;
		int ans = n;		// ��������n����ͨ�� 
		while(m--) {		// ���m���� 
			scanf("%d%d", &a, &b);	// ��ӣ�a,b���� 
			int fa = find(a);
			int fb = find(b);
			if(fa != fb) {
				f[fa] = fb;	// ��fa���ص�fb���� 
				ans--;
			}
		} 
		printf("%d\n", ans); 
	}
	return 0;
}

