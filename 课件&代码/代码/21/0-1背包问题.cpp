/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
const int maxn = 20;
int n, c; // ��Ʒ�����ͱ�������
int w[maxn], v[maxn];	// �ֱ����ÿ����Ʒ�������ͼ�ֵ 
int b[maxn];	// b[i] == 0 ��ʾ��Ʒi���ڱ������� 
int e[maxn];	// ���ŷ��� 
int ans;	// ��������ܼ�ֵ 
int left;	// ��¼���������б���ʣ������� 
// ���Խ�ÿ����Ʒװ�����ó����� 
void dfs(int cur) {
	if(cur==n) {	// �Ѿ�������� 
		int cv = 0;	// ��ʾ�ڵ�ǰ״̬�±��������Ʒ���ܼ�ֵ 
		for(int i=0; i<n; i++) {
			if(b[i]) cv += v[i];
		}
		if(cv>ans) {	// ���ֱ�ans���� 
			ans = cv;
			for(int i=0; i<n; i++) {	// ��¼��ǰ���ŵķ��� 
				e[i] = b[i];
			}
		}
	} else {
		// ÿ����Ʒֻ�����������0��ʾ���ڱ����� ,1��ʾ�� 
		if(left>=w[cur]) {	// ʣ�µ�������װ�µ�ǰ����Ʒ , ����������ֱ�Ӳ��� 
			left -= w[cur];
			b[cur] = 1;
			dfs(cur+1);
			left += w[cur];	// ���� 
		} 
		b[cur] = 0;	// �����뱳������� 
		dfs(cur+1);
	}
	
}
int main() {
	while(scanf("%d%d", &n, &c)==2) {
		for(int i=0; i<n; i++) scanf("%d", &w[i]);
		for(int i=0; i<n; i++) scanf("%d", &v[i]);
		ans = 0;
		left = c;
		dfs(0);
		printf("%d\n", ans);
		for(int i=0; i<n; i++) {	// ��¼��ǰ���ŵķ��� 
			printf("��%d����Ʒ%s\n",i+1, e[i]>0?"����":"����" );
		}
	}
	return 0;
}

