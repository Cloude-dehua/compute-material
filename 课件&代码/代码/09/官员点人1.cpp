/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
const int maxn = 25;
int vis[maxn];	// vis[i]==1��ʾ���Ϊi�����ڶ����У�vis[i]==0�Ѿ������� 
int n, k, m;
// p��ʾ��ǰ���±꣬ d��ʾ���� x��ʾ���ȥ������ 
int dian(int p, int d, int x) {
	while(x--) {
		do{
			p += d;	
			if(p>n) p = 1;	// ��Ϊ��ѭ�����ˣ�����Ƿ�Խ�� 
			if(p<1) p = n;
		} while(vis[p]==0);	// �����Ѿ�����ȥ���� 
	}
	return p;
}
int main() {
	
	while(scanf("%d%d%d", &n, &k, &m)==3) {
		for(int i=1; i<=n; i++) vis[i] = 1;
//		memset(vis, 1, sizeof(vis));	// memsetֻ�ܽ������ʼ��Ϊ0��-1
		int left = n;	// ʣ�µ���
		int p1 = n;	// A��Ա��ǰָ�����
		int p2 = 1;	// B��Ա��ǰָ����˵ı�� 
		while(left>0) {
			p1 = dian(p1, 1, k);
			p2 = dian(p2, -1, m);
			vis[p1] = vis[p2] = 0;	// �ѵ�ǰ�㵽�˱�־Ϊ��ȥ 
			printf("%d", p1);
			left--;
			if(p1!=p2) {	// ��A��B�ĵ��˲�һ��ʱ����B������� 
				printf(" %d", p2);
				left--;
			}
			if(left>0) printf(",");
		}
		printf("\n");	 
	}
	return 0;
}

