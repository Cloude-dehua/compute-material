/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
#include <algorithm>
using namespace std;
 
const int maxn = 2000 + 10; 
int nong[maxn];	// �� 
int qi[maxn];	// ��ʿ���� 
int main() {
	int n , m;
	while(scanf("%d%d", &n, &m) == 2 && !(n==0 && m==0)) {
		for(int i=0; i<n; i++) scanf("%d", &nong[i] );
		for(int i=0; i<m; i++) scanf("%d", &qi[i]);
		sort(nong, nong+n);
		sort(qi, qi+m);
		int j = 0;
		int ans = 0;	// ��Ӷ�� 
		for(int i=0; i<m; i++) {// �������͵���������ÿ����ʿ�Ƿ��Ӷ 
			if(qi[i]>=nong[j]) {
				j++;	// ����һ����
				ans += qi[i];	// 
				if(j==n) break;	// �Ѿ����� 
			}
		}
		if(j==n) {
			printf("%d\n", ans); 
		} else {
			printf("No\n");
		}
		 
	} 
	return 0;
}

