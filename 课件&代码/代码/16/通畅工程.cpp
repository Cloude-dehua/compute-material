#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10; 
int f[maxn];		// f[i]����i���ĸ����,f[i]==i��ʾi�Ǹ���� 
int find(int x) {
// ��x�������ĸ���� 
//	while(x!=f[x]) {	// x���Ǹ���� 
//		x = f[x];		// xָ�򸸽�� 
//	}
//	return x;
	return x==f[x]?x:(f[x]=find(f[x]));		// ��·��ѹ���Ĳ��ң��Ӳ���·���ϵĽ��ȫ��ֱ�ӹ����ڸ��� 
}
 
int main(){
	int n, m;
	while(scanf("%d%d", &n, &m)==2 && n) {
		for(int i=1; i<=n; i++) f[i] = i;		// ÿ�����㶼��һ����ͨ�飨���ϣ�����
		int a, b;
		int cnt = n;	// ����ÿ�����㶼��һ����ͨ�� 
		while(m--) {	// ����m���� 
			scanf("%d%d", &a, &b);
			int fa = find(a);
			int fb = find(b);
			if(fa != fb) {	// ����㲻һ��������һ������ 
				f[fa] = fb;	// ��fa��������ص�fb���� 
				cnt--;			// �ϲ�����ͨ��������һ 
			}
		} 
		printf("%d\n", cnt-1);	// ��Ҫ���ӱߵ����� 
	}

	return 0;
}

