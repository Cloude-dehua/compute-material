#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>

typedef long long ll;
const int maxn = 100+10;
struct E {	// �� 
	int u, w;	//�ߵĶ���
	int weight;	//�ߵ�Ȩֵ  
} es[maxn];
int f[maxn];	// f[i]��ʾi���ĸ��ڵ� 

bool cmp(E a, E b) {
	return a.weight < b.weight;
} 

int find(int a) {
	return a==f[a]?a:f[a] = find(f[a]);
}
int main(){
	int n;
	while(scanf("%d", &n)==1 && n) {	// n������
		for(int i=0; i<n*(n-1)/2; i++) {	// ����n*(n-1)/2���� 
			scanf("%d%d%d", &es[i].u, &es[i].w, &es[i].weight);
		} 
		for(int i=1; i<=n; i++) f[i]=i;	// ��ʼ��ÿ�����㶼��һ����ͨ�� 
		std::sort(es, es+n*(n-1)/2, cmp);	// �����б߽�����������
		int ans = 0;
		for(int i=0, cnt=0; cnt<n && i<n*(n-1)/2; i++) {	// ��С���������бߣ�cnt���Ѿ���ӵ��������еı��� 
			int fu = find(es[i].u);		// ����u��w���������ĸ�����ͨ�飩 
			int fw = find(es[i].w);
			if(fu!=fw) {	// ����ͬһ����ͨ�飬������������� 
				f[fu] = fw;	// �ϲ��� 
				ans += es[i].weight;		// �ۼ�Ȩֵ
				cnt++; 
			}
		} 
		printf("%d\n", ans); 
	}
	return 0;
}

